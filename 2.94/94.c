#include <stdio.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
	unsigned s = f >> 31;
	unsigned e = (f >> 23) & 0xFF;
	unsigned m = f & 0x7FFFFF;

	// 所有变量在开头声明（C90 兼容）

	unsigned is_special=0;
	unsigned is_denorm;
	unsigned is_overflow;
	unsigned special_mask;
	unsigned denorm_mask;
	unsigned overflow_mask;
	unsigned norm_cond;
	unsigned e_norm=0;
	unsigned m_norm;
	unsigned m_shifted;
	unsigned carry;
	unsigned e_denorm;
	unsigned m_denorm;
	unsigned e_overflow;
	unsigned m_overflow;
	unsigned e_final;
	unsigned m_final;
	unsigned normal_result;

	// 生成掩码（无比较，无分支）
	is_special = ((e ^ 0xFF) - 1) >> 31;
	is_denorm = ((e - 1) >> 31);
	is_overflow = ((e ^ 0xFE) - 1) >> 31;

	special_mask = ~is_special + 1;
	denorm_mask = ~is_denorm + 1;
	overflow_mask = ~is_overflow + 1;

	norm_cond = ~special_mask & ~denorm_mask & ~overflow_mask;

	// 规格化情况
	e_norm = e + 1;
	m_norm = m;

	// 非规格化情况
	m_shifted = m << 1;
	carry = (m_shifted >> 23) & 1;
	e_denorm = carry;
	m_denorm = m_shifted & 0x7FFFFF;

	// 溢出情况
	e_overflow = 0xFF;
	m_overflow = 0;

	// 按掩码选择
	e_final = (norm_cond & e_norm) |
		(denorm_mask & e_denorm) |
		(overflow_mask & e_overflow);

	m_final = (norm_cond & m_norm) |
		(denorm_mask & m_denorm) |
		(overflow_mask & m_overflow);

	normal_result = (s << 31) | (e_final << 23) | m_final;

	return (special_mask & f) | (~special_mask & normal_result);
}

// 辅助函数
float bits_to_float(float_bits f) {
	return *(float*)&f;
}

float_bits float_to_bits(float f) {
	return *(float_bits*)&f;
}

int main() {
	// 测试用例
	float_bits nan_bits = 0x7FC00000;
	float_bits inf_bits = 0x7F800000;

	float_bits neg_inf_bits = 0xFF800000;

	struct {
		float input;
		float expected;
	} tests[] = {
		{1.0f, 2.0f},
		{-1.0f, -2.0f},
		{0.0f, 0.0f},
		{1.5f, 3.0f},
		{0.5f, 1.0f},
		{1.0e-38f, 2.0e-38f},
		{-1.0e-38f, -2.0e-38f},
		{1.0e38f, 2.0e38f},
		{-1.0e38f, -2.0e38f},
	};

	// 特殊值测试

	int passed = 0;
	int failed = 0;
	int i;

	printf("=== 普通数值测试 ===\n");
	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		float_bits input_bits = float_to_bits(tests[i].input);
		float_bits output_bits = float_twice(input_bits);
		float output = bits_to_float(output_bits);

		float diff = output - tests[i].expected;
		if (diff < 0) diff = -diff;

		if (diff < 1e-6) {
			printf("✓ %g * 2 = %g\n", tests[i].input, output);
			passed++;
		}
		else {
			printf("✗ %g * 2 = %g (期望 %g)\n", tests[i].input, output, tests[i].expected);
			failed++;
		}
	}

	printf("\n=== 特殊值测试 ===\n");
	printf("NaN -> 0x%08X (期望 0x7FC00000)\n", float_twice(nan_bits));
	printf("+∞ -> 0x%08X (期望 0x7F800000)\n", float_twice(inf_bits));
	printf("-∞ -> 0x%08X (期望 0xFF800000)\n", float_twice(neg_inf_bits));

	printf("\n通过: %d, 失败: %d\n", passed, failed);
	return 0;
}
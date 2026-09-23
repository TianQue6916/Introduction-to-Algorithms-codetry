//////#define _CRT_SECURE_NO_WARNINGS  // 禁用scanf安全警告
//////#include <stdio.h>
//////#include <stdlib.h>
//////
//////// ==================== 常量定义 ====================
//////#define MAX_PEOPLE 100
//////
//////// ==================== 函数声明 ====================
//////void print_menu();
//////int get_valid_input(const char* prompt, int min, int max);
//////void initialize_array(int people[], int n);
//////void print_circle(int people[], int n, int step);
//////void josephus_array_version();
//////void josephus_linked_list_version();
//////int josephus_recursive_formula(int n, int m);
//////void josephus_recursive_version();
//////void compare_implementations();
//////void clear_input_buffer();
//////
//////// ==================== 工具函数 ====================
//////
//////// 清除输入缓冲区
//////void clear_input_buffer() {
//////    int c;
//////    while ((c = getchar()) != '\n' && c != EOF) {}
//////}
//////
//////// 打印菜单
//////void print_menu() {
//////    printf("\n========== 约瑟夫环问题求解器 ==========\n");
//////    printf("1. 使用数组实现约瑟夫环\n");
//////    printf("2. 使用链表实现约瑟夫环\n");
//////    printf("3. 使用递归公式求解幸存者\n");
//////    printf("4. 比较不同实现方式\n");
//////    printf("5. 退出程序\n");
//////    printf("=======================================\n");
//////    printf("请选择功能 (1-5): ");
//////}
//////
//////// 获取有效输入
//////int get_valid_input(const char* prompt, int min, int max) {
//////    int value;
//////    char buffer[100];
//////
//////    while (1) {
//////        printf("%s", prompt);
//////
//////        // 使用fgets和sscanf代替scanf
//////        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
//////            printf("输入错误！\n");
//////            continue;
//////        }
//////
//////        if (sscanf(buffer, "%d", &value) != 1) {
//////            printf("输入错误，请输入数字！\n");
//////            continue;
//////        }
//////
//////        if (value >= min && value <= max) {
//////            return value;
//////        }
//////
//////        printf("输入无效，请输入%d到%d之间的数字！\n", min, max);
//////    }
//////}
//////
//////// 初始化人员数组
//////void initialize_array(int people[], int n) {
//////    for (int i = 0; i < n; i++) {
//////        people[i] = 1;  // 1表示在圈内
//////    }
//////}
//////
//////// 打印当前圆圈状态
//////void print_circle(int people[], int n, int step) {
//////    printf("\n第%d步 - 当前圆圈状态: ", step);
//////    for (int i = 0; i < n; i++) {
//////        if (people[i] == 1) {
//////            printf("[%d] ", i + 1);
//////        }
//////        else {
//////            printf(" X  ");
//////        }
//////    }
//////    printf("\n");
//////}
//////
//////// ==================== 数组实现 ====================
//////
//////void josephus_array_version() {
//////    printf("\n=== 数组实现约瑟夫环 ===\n");
//////
//////    int n = get_valid_input("请输入总人数 N (1-100): ", 1, MAX_PEOPLE);
//////    int m = get_valid_input("请输入报数 M (1-100): ", 1, MAX_PEOPLE);
//////
//////    int people[MAX_PEOPLE];
//////    initialize_array(people, n);
//////
//////    int remaining = n;
//////    int count = 0;
//////    int index = 0;
//////    int step = 1;
//////
//////    printf("\n开始模拟约瑟夫环...\n");
//////    printf("初始状态: ");
//////    for (int i = 0; i < n; i++) {
//////        printf("[%d] ", i + 1);
//////    }
//////    printf("\n");
//////
//////    printf("\n出列顺序: ");
//////
//////    while (remaining > 0) {
//////        if (people[index] == 1) {
//////            count++;
//////
//////            if (count == m) {
//////                people[index] = 0;
//////                remaining--;
//////                count = 0;
//////
//////                printf("%d", index + 1);
//////                if (remaining > 0) {
//////                    printf(" -> ");
//////                    print_circle(people, n, step);
//////                    step++;
//////                }
//////            }
//////        }
//////
//////        index = (index + 1) % n;
//////    }
//////
//////    printf("\n\n所有人都已出列！\n");
//////}
//////
//////// ==================== 链表结构定义 ====================
//////
//////// 链表节点结构
//////typedef struct Node {
//////    int id;
//////    struct Node* next;
//////} Node;
//////
//////// 创建新节点
//////Node* create_node(int id) {
//////    Node* newNode = (Node*)malloc(sizeof(Node));
//////    if (newNode == NULL) {
//////        printf("内存分配失败！\n");
//////        exit(1);
//////    }
//////    newNode->id = id;
//////    newNode->next = NULL;
//////    return newNode;
//////}
//////
//////// 创建循环链表
//////Node* create_circular_list(int n) {
//////    if (n <= 0) return NULL;
//////
//////    Node* head = create_node(1);
//////    Node* current = head;
//////
//////    for (int i = 2; i <= n; i++) {
//////        Node* newNode = create_node(i);
//////        current->next = newNode;
//////        current = newNode;
//////    }
//////
//////    current->next = head;  // 形成环
//////    return head;
//////}
//////
//////// 释放链表内存
//////void free_linked_list(Node* head) {
//////    if (head == NULL) return;
//////
//////    Node* current = head->next;
//////    while (current != head) {
//////        Node* temp = current;
//////        current = current->next;
//////        free(temp);
//////    }
//////    free(head);
//////}
//////
//////// ==================== 链表实现 ====================
//////
//////void josephus_linked_list_version() {
//////    printf("\n=== 链表实现约瑟夫环 ===\n");
//////
//////    int n = get_valid_input("请输入总人数 N (1-100): ", 1, MAX_PEOPLE);
//////    int m = get_valid_input("请输入报数 M (1-100): ", 1, MAX_PEOPLE);
//////
//////    if (n <= 0 || m <= 0) {
//////        printf("参数错误！\n");
//////        return;
//////    }
//////
//////    // 创建循环链表
//////    Node* current = create_circular_list(n);
//////    Node* prev = NULL;
//////
//////    // 找到最后一个节点
//////    Node* last = current;
//////    while (last->next != current) {
//////        last = last->next;
//////    }
//////    prev = last;
//////
//////    printf("\n开始模拟约瑟夫环...\n");
//////    printf("初始人员: ");
//////    Node* temp = current;
//////    do {
//////        printf("[%d] ", temp->id);
//////        temp = temp->next;
//////    } while (temp != current);
//////    printf("\n");
//////
//////    printf("\n出列顺序: ");
//////
//////    int step = 1;
//////    while (current->next != current) {
//////        // 报数
//////        for (int i = 1; i < m; i++) {
//////            prev = current;
//////            current = current->next;
//////        }
//////
//////        // 出列
//////        printf("%d", current->id);
//////        if (current->next != current) {
//////            printf(" -> ");
//////
//////            // 打印剩余人员
//////            printf("\n第%d步 - 剩余人员: ", step);
//////            Node* survivor = current->next;
//////            Node* start = survivor;
//////            do {
//////                printf("[%d] ", survivor->id);
//////                survivor = survivor->next;
//////            } while (survivor != start);
//////            printf("\n");
//////            step++;
//////        }
//////
//////        // 删除节点
//////        prev->next = current->next;
//////        Node* to_delete = current;
//////        current = current->next;
//////        free(to_delete);
//////    }
//////
//////    printf("\n\n最后幸存者: [%d]\n", current->id);
//////
//////    // 清理内存
//////    free(current);
//////}
//////
//////// ==================== 递归公式实现 ====================
//////
//////// 递归公式：J(n, m) = (J(n-1, m) + m) % n
//////int josephus_recursive_formula(int n, int m) {
//////    if (n == 1) return 0;  // 只有一个人时，编号0的人存活
//////    return (josephus_recursive_formula(n - 1, m) + m) % n;
//////}
//////
//////void josephus_recursive_version() {
//////    printf("\n=== 递归公式求解幸存者 ===\n");
//////
//////    int n = get_valid_input("请输入总人数 N (1-100): ", 1, MAX_PEOPLE);
//////    int m = get_valid_input("请输入报数 M (1-100): ", 1, MAX_PEOPLE);
//////
//////    int survivor = josephus_recursive_formula(n, m) + 1;  // 转换为从1开始编号
//////
//////    printf("\n计算结果：\n");
//////    printf("总人数: %d\n", n);
//////    printf("报数到: %d\n", m);
//////    printf("最后幸存者编号: %d\n", survivor);
//////
//////    // 验证公式
//////    printf("\n验证：\n");
//////    printf("公式：J(%d, %d) = (J(%d, %d) + %d) %% %d\n",
//////        n, m, n - 1, m, m, n);
//////
//////    if (n <= 10) {
//////        printf("逐步计算：\n");
//////        for (int i = 1; i <= n; i++) {
//////            int result = josephus_recursive_formula(i, m);
//////            printf("J(%d, %d) = %d\n", i, m, result);
//////        }
//////    }
//////}
//////
//////// ==================== 比较函数 ====================
//////
//////void compare_implementations() {
//////    printf("\n=== 比较不同实现方式 ===\n");
//////
//////    int n = get_valid_input("请输入总人数 N (1-50): ", 1, 50);
//////    int m = get_valid_input("请输入报数 M (1-50): ", 1, 50);
//////
//////    printf("\n对同一问题(%d人，报数%d)的解决方案：\n", n, m);
//////    printf("=======================================\n");
//////
//////    // 1. 递归公式结果
//////    printf("1. 递归公式结果：\n");
//////    int recursive_result = josephus_recursive_formula(n, m) + 1;
//////    printf("   幸存者编号: %d\n", recursive_result);
//////
//////    // 2. 数组模拟结果
//////    printf("\n2. 数组模拟结果：\n");
//////    int people[MAX_PEOPLE];
//////    initialize_array(people, n);
//////
//////    int remaining = n;
//////    int count = 0;
//////    int index = 0;
//////    int last_survivor = 0;
//////
//////    while (remaining > 0) {
//////        if (people[index] == 1) {
//////            count++;
//////            if (count == m) {
//////                last_survivor = index + 1;
//////                people[index] = 0;
//////                remaining--;
//////                count = 0;
//////            }
//////        }
//////        index = (index + 1) % n;
//////    }
//////    printf("   幸存者编号: %d\n", last_survivor);
//////
//////    // 3. 链表模拟结果
//////    printf("\n3. 链表模拟结果：\n");
//////    if (n > 0 && m > 0) {
//////        Node* current = create_circular_list(n);
//////        Node* prev = NULL;
//////
//////        // 找到最后一个节点
//////        Node* last = current;
//////        while (last->next != current) {
//////            last = last->next;
//////        }
//////        prev = last;
//////
//////        while (current->next != current) {
//////            for (int i = 1; i < m; i++) {
//////                prev = current;
//////                current = current->next;
//////            }
//////
//////            prev->next = current->next;
//////            Node* to_delete = current;
//////            current = current->next;
//////            free(to_delete);
//////        }
//////
//////        printf("   幸存者编号: %d\n", current->id);
//////        free(current);
//////    }
//////
//////    printf("\n=======================================\n");
//////    printf("结论：三种方法得到的结果一致！\n");
//////}
//////
//////// ==================== 主函数 ====================
//////
//////int main() {
//////    printf("欢迎使用约瑟夫环问题求解器！\n");
//////
//////    int choice;
//////
//////    do {
//////        print_menu();
//////        choice = get_valid_input("", 1, 5);
//////
//////        switch (choice) {
//////        case 1:
//////            josephus_array_version();
//////            break;
//////
//////        case 2:
//////            josephus_linked_list_version();
//////            break;
//////
//////        case 3:
//////            josephus_recursive_version();
//////            break;
//////
//////        case 4:
//////            compare_implementations();
//////            break;
//////
//////        case 5:
//////            printf("\n感谢使用，再见！\n");
//////            break;
//////
//////        default:
//////            printf("无效选择，请重新输入！\n");
//////        }
//////
//////        if (choice != 5) {
//////            printf("\n按Enter键继续...");
//////            clear_input_buffer();  // 使用专门的函数
//////        }
//////
//////    } while (choice != 5);
//////
//////    return 0;
//////}
////#include <stdio.h>
////
////int main() {
////    int n = 7, m = 3;  // 7个人，数到3出列
////
////    int people[100] = { 0 };
////    int alive = n;  // 剩余人数
////    int count = 0;  // 当前报数
////    int index = 0;  // 当前位置
////
////    // 标记所有人都在
////    for (int i = 0; i < n; i++) {
////        people[i] = 1;
////    }
////
////    // 开始淘汰
////    while (alive > 1) {
////        if (people[index] == 1) {
////            count++;
////            if (count == m) {
////                people[index] = 0;  // 淘汰
////                alive--;
////                count = 0;
////                printf("淘汰第%d号\n", index + 1);
////            }
////        }
////        index = (index + 1) % n;  // 循环到下一个人
////    }
////
////    // 找幸存者
////    for (int i = 0; i < n; i++) {
////        if (people[i] == 1) {
////            printf("最后幸存者是第%d号\n", i + 1);
////            break;
////        }
////    }
////
////    return 0;
////}
////
////
////
//#include <stdio.h>
//#include <stdlib.h>
//
//// 链表节点
//struct Node {
//	int id;
//	struct Node* next;
//};
//
//int main() {
//	int n = 7;  // 总人数
//	int m = 3;  // 报数到m出列
//
//	// 1. 创建循环链表
//	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
//	head->id = 1;
//	struct Node* current = head;
//
//	// 创建剩余节点
//	for (int i = 2; i <= n; i++) {
//		current->next = (struct Node*)malloc(sizeof(struct Node));
//		current = current->next;
//		current->id = i;
//	}
//	current->next = head;  // 形成环
//
//	// 2. 开始淘汰
//	printf("淘汰顺序：");
//
//	while (head->next != head) {  // 直到只剩一个人
//		// 数m-1个人
//		for (int i = 1; i < m - 1; i++) {
//			head = head->next;
//		}
//
//		// 淘汰下一个人
//		struct Node* temp = head->next;
//		printf("%d ", temp->id);
//
//		head->next = temp->next;  // 跳过被淘汰的节点
//		free(temp);               // 释放内存
//		head = head->next;        // 从下一个人开始
//	}
//
//	// 3. 输出幸存者
//	printf("\n幸存者：%d\n", head->id);
//	free(head);
//
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

// 1. 定义链表节点结构
typedef struct Node {
    int id;
    struct Node* next;
} Node;

// 2. 创建新节点
Node* create_node(int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

// 3. 创建循环链表
Node* create_circle(int n) {
    if (n <= 0) return NULL;

    Node* head = create_node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        Node* new_node = create_node(i);
        current->next = new_node;
        current = new_node;
    }

    current->next = head;  // 形成环
    return head;
}

// 4. 打印当前圈子状态
void print_circle(Node* start, int total_people) {
    if (start == NULL) return;

    Node* current = start;
    printf("当前圈子：");

    for (int i = 0; i < total_people; i++) {
        printf("[%d]", current->id);
        if (i < total_people - 1) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

// 5. 计算剩余人数
int count_remaining(Node* start) {
    if (start == NULL) return 0;

    int count = 1;
    Node* current = start->next;

    while (current != start) {
        count++;
        current = current->next;
    }

    return count;
}

// 6. 淘汰一个人
void eliminate_person(Node** current, Node** prev, int m) {
    // 找到要淘汰的人
    for (int i = 1; i < m; i++) {
        *prev = *current;
        *current = (*current)->next;
    }

    // 淘汰当前节点
    printf("淘汰 [%d] 号\n", (*current)->id);

    // 从链表中删除
    (*prev)->next = (*current)->next;

    // 释放内存
    Node* temp = *current;
    *current = (*current)->next;  // 从下一个人开始
    free(temp);
}

// 7. 约瑟夫环主函数
void josephus_main(Node* head, int n, int m) {
    Node* current = head;
    Node* prev = NULL;

    // 找到最后一个节点（为了首次淘汰操作方便）
    while (prev == NULL || prev->next != head) {
        if (prev == NULL) {
            prev = head;
        }
        else {
            prev = prev->next;
        }
    }

    int step = 1;

    while (current->next != current) {
        printf("\n第%d步：", step);
        eliminate_person(&current, &prev, m);

        // 显示剩余人员
        printf("剩余人数：%d\n", count_remaining(current));

        step++;
    }

    printf("\n🎉 最后幸存者：[%d] 号 🎉\n", current->id);

    // 释放最后一个节点
    free(current);
}

// 8. 获取用户输入
void get_input(int* n, int* m) {
    printf("请输入总人数：");
    scanf("%d", n);

    printf("请输入报数到几出列：");
    scanf("%d", m);
}

// 9. 主函数
int main() {
    int n, m;

    get_input(&n, &m);

    // 创建循环链表
    Node* circle = create_circle(n);

    // 显示初始状态
    printf("\n初始状态：");
    print_circle(circle, n);

    // 执行约瑟夫环
    josephus_main(circle, n, m);

    return 0;
}
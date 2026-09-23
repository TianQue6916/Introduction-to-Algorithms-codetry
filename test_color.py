# ============================================================
# Mind 语言 — 完整功能示例文件
# ============================================================
# 写完一行后按 Enter，插件自动分析整份文件。
# 以 # @d 开头的注释会被视为"需求"，自动生成 Python + C 代码。
# ============================================================

# ============================================================
# 🎯 示例 1: 基础算法 — 链表反转
# ============================================================

# @d 实现链表反转函数
# @d 要求: 输入链表头节点，返回反转后的新头节点
# @d 需要考虑空链表和单节点的情况

# 定义链表节点类
class ListNode:
    """单链表节点"""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverse_list(head: ListNode) -> ListNode:
    """
    反转链表 - 三指针法
    输入: 链表头节点
    输出: 反转后的新头节点
    处理空链表和单节点情况
    """
    # 如果链表为空或只有一个节点，直接返回头节点
    if head is None or head.next is None:
        return head
    
    # 初始化三指针: prev指向None, curr指向头节点
    prev = None
    curr = head
    
    # 遍历链表，逐个反转next指针
    while curr is not None:
        # 保存当前节点的下一个节点
        next_node = curr.next
        # 反转当前节点的next指向prev
        curr.next = prev
        # 移动prev和curr指针
        prev = curr
        curr = next_node
    
    # 返回新头节点（原链表的尾节点，即prev）
    return prev

# ============================================================
# 🎯 示例 2: 数据处理 — 数组去重
# ============================================================

# @d 实现数组去重函数
# @d 输入: 整数数组，输出: 去重后的新数组
# @d 要求保持原顺序，使用双指针法

def remove_duplicates(arr: list) -> int:
    """
    从已排序数组中移除重复元素（原地修改）
    使用双指针法（快慢指针）
    输入: 已排序的整数数组arr
    输出: 去重后的新长度
    注意: 函数会修改原数组，使得前len个元素为去重后的结果
    """
    # 如果数组为空，直接返回0
    if not arr:
        return 0
    
    # write_pos 指向下一个不重复元素应该放置的位置
    write_pos = 1
    
    # 从第二个元素开始遍历（read_pos指向当前读取元素）
    for read_pos in range(1, len(arr)):
        # 如果当前读取元素与前一个元素不同，则保留当前元素
        if arr[read_pos] != arr[read_pos - 1]:
            arr[write_pos] = arr[read_pos]
            write_pos += 1  # 移动写入位置
    
    # 返回去重后的长度
    return write_pos

# ============================================================
# 🎯 示例 3: 字符串处理 — 回文判断
# ============================================================

# @d 实现回文判断函数
# @d 输入: 字符串 s，输出: bool
# @d 忽略大小写和空格

def is_palindrome(s: str) -> bool:
    """
    判断字符串是否为回文（忽略大小写和非字母数字字符）
    使用双指针从两端向中间扫描
    输入: 字符串s
    输出: 布尔值
    """
    left = 0
    right = len(s) - 1
    
    while left < right:
        # 跳过左边非字母数字字符
        if not s[left].isalnum():
            left += 1
            continue
        # 跳过右边非字母数字字符
        if not s[right].isalnum():
            right -= 1
            continue
        # 比较当前字符（忽略大小写）
        if s[left].lower() != s[right].lower():
            return False
        # 继续向中间移动
        left += 1
        right -= 1
    
    return True

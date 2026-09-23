# tree 类：基于列表的基本数据结构操作类
class tree:
    def __init__(self):
        """初始化空列表"""
        self.A = []

    def insert(self, value):
        """向列表添加元素"""
        self.A.append(value)

    def search(self, value):
        """搜索元素（若存在则删除）并返回是否存在"""
        if value in self.A:
            self.A.remove(value)
            return True
        return False

    def delete(self, value):
        """删除指定元素，返回是否成功"""
        if value in self.A:
            self.A.remove(value)
            return True
        return False


# TreeNode 类：二叉搜索树节点，包含键、值、左右子节点及高度
class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.height = 1  # 新节点初始高度为1


# BTS 类：继承 tree，实现二叉搜索树（带 AVL 平衡）
class BTS(tree):
    def __init__(self):
        """初始化父类列表，同时设置根节点为 None"""
        super().__init__()
        self.root = None

    def search(self, key):
        """二叉搜索树查找，返回节点值或 None"""
        return self._search_recursive(self.root, key)

    def _search_recursive(self, node, key):
        """递归查找辅助函数"""
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search_recursive(node.left, key)
        return self._search_recursive(node.right, key)

    def insert(self, key, value):
        """插入键值对，自动保持平衡"""
        self.root = self._insert_recursive(self.root, key, value)

    def _insert_recursive(self, node, key, value):
        """递归插入并平衡"""
        # 1. 标准 BST 插入
        if node is None:
            return TreeNode(key, value)
        if key < node.key:
            node.left = self._insert_recursive(node.left, key, value)
        elif key > node.key:
            node.right = self._insert_recursive(node.right, key, value)
        else:
            # 键已存在，更新值
            node.value = value
            return node

        # 2. 更新当前节点的高度
        node.height = 1 + max(self._get_height(node.left), self._get_height(node.right))

        # 3. 计算平衡因子
        balance = self._get_balance(node)

        # 4. 如果失衡，进行旋转
        # 左左情况：右旋
        if balance > 1 and key < node.left.key:
            return self._right_rotate(node)
        # 右右情况：左旋
        if balance < -1 and key > node.right.key:
            return self._left_rotate(node)
        # 左右情况：先左旋再右旋
        if balance > 1 and key > node.left.key:
            node.left = self._left_rotate(node.left)
            return self._right_rotate(node)
        # 右左情况：先右旋再左旋
        if balance < -1 and key < node.right.key:
            node.right = self._right_rotate(node.right)
            return self._left_rotate(node)

        return node

    def _left_rotate(self, z):
        """左旋转（对应 right_reserve）"""
        y = z.right
        T2 = y.left

        # 旋转
        y.left = z
        z.right = T2

        # 更新高度
        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))

        return y

    def _right_rotate(self, z):
        """右旋转（对应 left_reserve）"""
        y = z.left
        T3 = y.right

        # 旋转
        y.right = z
        z.left = T3

        # 更新高度
        z.height = 1 + max(self._get_height(z.left), self._get_height(z.right))
        y.height = 1 + max(self._get_height(y.left), self._get_height(y.right))

        return y

    @staticmethod
    def _get_height(node):
        """获取节点高度，空节点高度为0"""
        if node is None:
            return 0
        return node.height

    def _get_balance(self, node):
        """计算平衡因子"""
        if node is None:
            return 0
        return self._get_height(node.left) - self._get_height(node.right)

    # 补全方法：left_reserve 和 right_reserve（已用旋转实现）
    def left_reserve(self, root):
        """左旋转的公开接口（保留原方法名）"""
        if root is None:
            return None
        return self._left_rotate(root)

    def right_reserve(self, root):
        """右旋转的公开接口（保留原方法名）"""
        if root is None or root.left is None:
            return root
        return self._right_rotate(root)

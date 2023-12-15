class LinkNode:
    def __init__(self, val):
        self.val = val
        self.next = None


def create_link_list(nums: list):
    if len(nums) == 0:
        return None
    head = LinkNode(nums[0])
    cur = head
    for i in range(1, len(nums)):
        cur.next = LinkNode(nums[i])
        cur = cur.next
    return head


def delete_link_list(head: LinkNode):
    while head:
        head = head.next
        del head


def print_link_list(head: LinkNode):
    while head:
        if head.next is None:
            print(head.val)
            break
        print(head.val, end=", ")
        head = head.next


def insert_link_node(head: LinkNode, target_index: int, val: int):
    if head is None:
        return LinkNode(val)
    cur = head
    for _ in range(target_index - 1):
        cur = cur.next
    cur.next = LinkNode(val)
    return head


def get_link_list_length(head: LinkNode):
    length = 0
    while head:
        length += 1
        head = head.next
    return length


def get_element_val(head: LinkNode, index: int):
    if index < 0:
        return None
    cur = head
    for _ in range(index):
        cur = cur.next
    return cur.val


def get_element_idx(head: LinkNode, val: int):
    if head is None:
        return -1
    cur = head
    idx = 0
    while cur:
        if cur.val == val:
            return idx
        cur = cur.next
        idx += 1
    return -1

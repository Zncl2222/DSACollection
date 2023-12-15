import pytest
from link_list.link_list import (
    create_link_list,
    delete_link_list,
    insert_link_node,
    get_link_list_length,
    get_element_val,
    get_element_idx,
)


@pytest.fixture
def sample_linked_list():
    return create_link_list([1, 2, 3, 4, 5])


@pytest.mark.parametrize(
    "nums, expected_length",
    [
        ([1, 2, 3, 4, 5], 5),
        ([], 0),
        ([10, 20, 30], 3),
    ],
)
def test_create_link_list(nums, expected_length):
    head = create_link_list(nums)
    assert get_link_list_length(head) == expected_length


def test_delete_link_list(sample_linked_list):
    head = sample_linked_list
    delete_link_list(head)


@pytest.mark.parametrize(
    "target_index, val, expected_val",
    [
        (2, 10, 10),
        (1, 100, 100),
        (5, 50, 50),
    ],
)
def test_insert_link_node(sample_linked_list, target_index, val, expected_val):
    new_head = insert_link_node(sample_linked_list, target_index, val)
    assert get_element_val(new_head, target_index) == expected_val


def test_get_link_list_length(sample_linked_list):
    assert get_link_list_length(sample_linked_list) == 5


@pytest.mark.parametrize(
    "index, expected_val",
    [
        (2, 3),
        (0, 1),
        (4, 5),
    ],
)
def test_get_element_val(sample_linked_list, index, expected_val):
    assert get_element_val(sample_linked_list, index) == expected_val


@pytest.mark.parametrize(
    "val, expected_index",
    [
        (4, 3),
        (1, 0),
        (10, -1),
    ],
)
def test_get_element_idx(sample_linked_list, val, expected_index):
    assert get_element_idx(sample_linked_list, val) == expected_index

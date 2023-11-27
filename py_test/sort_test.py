import pytest
from sorting.bubble_sort.bubble_sort import bubble_sort
from sorting.selection_sort.selection_sort import selection_sort
from sorting.shell_sort.shell_sort import shell_sort
from sorting.insertion_sort.insertion_sort import insertion_sort
from sorting.quick_sort.quick_sort import quick_sort


@pytest.mark.parametrize(
    "input_list, expected",
    [
        ([4, 3, 2, 1], [1, 2, 3, 4]),
        ([5, 8, 1, 3, 6], [1, 3, 5, 6, 8]),
        ([1], [1]),
        ([], []),
        ([9, 7, 5, 3, 1], [1, 3, 5, 7, 9]),
        ([-1, -66, 2, 64, 8], [-66, -1, 2, 8, 64]),
    ],
)
def test_bubble_sort(input_list, expected):
    bubble_sort(input_list)
    assert input_list == expected


@pytest.mark.parametrize(
    "input_list, expected",
    [
        ([4, 3, 2, 1], [1, 2, 3, 4]),
        ([5, 8, 1, 3, 6], [1, 3, 5, 6, 8]),
        ([1], [1]),
        ([], []),
        ([9, 7, 5, 3, 1], [1, 3, 5, 7, 9]),
        ([-1, -66, 2, 64, 8], [-66, -1, 2, 8, 64]),
    ],
)
def test_selection_sort(input_list, expected):
    selection_sort(input_list)
    assert input_list == expected


@pytest.mark.parametrize(
    "input_list, expected",
    [
        ([4, 3, 2, 1], [1, 2, 3, 4]),
        ([5, 8, 1, 3, 6], [1, 3, 5, 6, 8]),
        ([1], [1]),
        ([], []),
        ([9, 7, 5, 3, 1], [1, 3, 5, 7, 9]),
        ([-1, -66, 2, 64, 8], [-66, -1, 2, 8, 64]),
    ],
)
def test_shell_sort(input_list, expected):
    shell_sort(input_list)
    assert input_list == expected


@pytest.mark.parametrize(
    "input_list, expected",
    [
        ([4, 3, 2, 1], [1, 2, 3, 4]),
        ([5, 8, 1, 3, 6], [1, 3, 5, 6, 8]),
        ([1], [1]),
        ([], []),
        ([9, 7, 5, 3, 1], [1, 3, 5, 7, 9]),
        ([-1, -66, 2, 64, 8], [-66, -1, 2, 8, 64]),
    ],
)
def test_insertion_sort(input_list, expected):
    insertion_sort(input_list)
    assert input_list == expected


@pytest.mark.parametrize(
    "input_list, expected",
    [
        ([4, 3, 2, 1], [1, 2, 3, 4]),
        ([5, 8, 1, 3, 6], [1, 3, 5, 6, 8]),
        ([1], [1]),
        ([], []),
        ([9, 7, 5, 3, 1], [1, 3, 5, 7, 9]),
        ([-1, -66, 2, 64, 8], [-66, -1, 2, 8, 64]),
    ],
)
def test_quick_sort(input_list, expected):
    input_list = quick_sort(input_list)
    assert input_list == expected

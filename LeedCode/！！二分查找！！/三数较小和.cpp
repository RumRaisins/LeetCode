void quick_sort(int *nums, int left, int right) {
	if (left >= right) return;
	int l = left, r = right;
	int x = nums[l];
	while (l < r) {
		while (l < r && nums[r] >= x) --r;
		if (l < r) nums[l++] = nums[r];
		while (l < r && nums[l] <= x) ++l;
		if (l < r) nums[r--] = nums[l];
	}
	nums[l] = x;
	quick_sort(nums, left, l - 1);
	quick_sort(nums, l + 1, right);
	return;
}

int two_sum_smaller(int *nums, int length, int target) {
	if (length <= 1) return 0;
	int head = 0, tail = length - 1;
	int ans = 0;
	while (head < tail) {
		while (head < tail && nums[head] + nums[tail] < target) ++head;
		if (head < tail) {
			ans += head;
			--tail;
		}
	}
	ans += (head * (head + 1)) / 2;
	return ans;
}

int three_sum_smaller(int *nums, int length, int target) {
	quick_sort(nums, 0, length - 1);
	int ans = 0;
	for (int i = 0; i < length; ++i) {
		ans += two_sum_smaller(nums + i + 1, length - i - 1, target - nums[i]);
	}
	return ans;

}
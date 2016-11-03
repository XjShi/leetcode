/**
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/

int climbStairs(int n) {
    if (n == 0)	return 0;
    if (n == 1)	return 1;
    if (n == 2)	return 2;

    int *r = malloc(sizeof(int) * n);
    r[0] = 1;
    r[1] = 2;
    for (int i=2; i<n; i++) {
    	r[i] = r[i - 1] + r[i - 2];
    }
    int ret = r[n - 1];
    free(r);
    return ret;
}
bool isMatch(const char *s, const char *p) {
	int N = strlen(p), M = strlen(s), n, m, temp;
	for(n = 0; n < N && m < M;){
		for(m = 0; m < M; ++m) {
			char cur_p = p[n], cur_s = s[m];
			int alternative = (n + 1 < N) && (p[n] == '*');
			if(cur_p == '.' || cur_p == cur_s) {
				// *
				if(alternative == 0) {
					n += 2; 
				}
			}
			else if(alternative == 0) {
				return 0;	
			}
		}
	}
	return 1;
}

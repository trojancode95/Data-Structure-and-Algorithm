#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007


bool isValidParenthesis(char *s) {
	stack<char>st;
	for (int i = 0; s[i] != '\0'; i++) {
		char ch = s[i];
		if (ch == '(')
			st.push(ch);
		else if (ch == ')') {
			if (st.empty() || st.top() != '(')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

int32_t main() {
	char s[100] = "((a+b)+(c-d+f))";
	if (isValidParenthesis(s))
		cout << "Valid Parenthesis" << endl;
	else
		cout << "Not a Valid Parenthesis" << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007

bool validParenthesis(string s) {
	stack<char>st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		else {
			if (st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
				return false;
			else if (st.top() == '(' && s[i] == ')')
				st.pop();
			else if (st.top() == '{' && s[i] == '}')
				st.pop();
			else if (st.top() == '[' && s[i] == ']')
				st.pop();
			else
				return false;
		}
	}
	return st.empty();
}

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << validParenthesis(s) << endl;
	}

	return 0;
}

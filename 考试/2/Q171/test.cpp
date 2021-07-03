#include <iostream>
#include <string>
#include <vector>

using namespace std;

class weibo {
public:
	int owner;
	int weiboid;
	int thetype;


	weibo(int thisowner, int thisid, int thistype) {
		owner = thisowner;
		weiboid = thisid;
		thetype = thistype;
	}
};

class user {
public:
	int id;
	int watch;
	vector<int> watchlist;
	int fans;
	vector<int> fanslist;
	int weibonum;
	vector<weibo*> weibolist;

	user(int thisid){
		id = thisid;
		watch = 0;
		fans = 0;
		weibonum = 0;
	}
};

int main() {
	int n = 0;
	cin >> n;
	cin.get();
	vector<user*> userlist;
	vector<weibo*> weibolist;
	int weibonum = 0;
	for (int i = 0; i <= n; ++i) {
		userlist.push_back(new user(i));
	}
	for (int i = 0; i < n; ++i) {
		string temp;
		getline(cin, temp);
		if (temp[0] == 'p') {
			int j = 5;
			int userid = 0;
			int weiboid = 0;
			int type = 0;
			while (temp[j] != ' ') {
				userid = userid * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != ' ') {
				weiboid = weiboid * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != '\0') {
				type = type * 10 + (temp[j] - '0');
				j++;
			}
			weibo* newweibo = new weibo(userid, weiboid, type);
			userlist[userid]->weibonum++;
			userlist[userid]->weibolist.push_back(newweibo);
			weibonum++;
			weibolist.push_back(newweibo);
		}
		else if (temp[0] == 'g' && temp[3] == 'R') {
			int j = 10;
			int userid = 0;
			int num = 0;
			int type = 0;
			while (temp[j] != ' ') {
				userid = userid * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != ' ') {
				num = num * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != '\0') {
				type = type * 10 + (temp[j] - '0');
				j++;
			}
			int count = 0;
			if (type == 0) {
				for (int k = userlist[userid]->weibonum - 1; k >= 0; --k) {
					if (count != 0) {
						cout << " ";
					}
					cout << userlist[userid]->weibolist[k]->weiboid;
					count++;
					if (count == num) {
						break;
					}
				}
				cout << endl;
			}
			else if (type == 1) {
				for (int k = weibonum - 1; k >= 0; --k) {
					if (count != 0) {
						cout << " ";
					}
					bool flag1 = false;
					bool flag2 = false;
					if (weibolist[k]->owner == userid) {
						flag1 = true;
						flag2 = true;
					}
					else {
						if (weibolist[k]->thetype != 0) {
							for (int l = 0; l < userlist[userid]->watch; ++l) {
								if (userlist[userid]->watchlist[l] == weibolist[k]->owner) {
									flag1 = true;
									break;
								}
							}
							for (int l = 0; l < userlist[userid]->fans; ++l) {
								if (userlist[userid]->fanslist[l] == weibolist[k]->owner) {
									flag2 = true;
									break;
								}
							}
						}
					}
					if (flag1 && flag2) {
						cout << weibolist[k]->weiboid;
						count++;
					}
					if (count == num) {
						break;
					}
				}
				cout << endl;
			}
			else if (type == 2) {
				for (int k = weibonum - 1; k >= 0; --k) {
					if (count != 0) {
						cout << " ";
					}
					bool flag = false;
					if (weibolist[k]->owner == userid) {
						flag = true;
					}
					else {
						if (weibolist[k]->thetype == 2) {
							for (int l = 0; l < userlist[weibolist[k]->owner]->fans; ++l) {
								if (userlist[weibolist[k]->owner]->fanslist[l] == userid) {
									flag = true;
									break;
								}
							}
						}
						else if (weibolist[k]->thetype == 1) {
							bool flag1 = false;
							bool flag2 = false;
							for (int l = 0; l < userlist[userid]->fans; ++l) {
								if (userlist[userid]->fanslist[l] == weibolist[k]->owner) {
									flag1 = true;
									break;
								}
							}
							for (int l = 0; l < userlist[weibolist[k]->owner]->fans; ++l) {
								if (userlist[weibolist[k]->owner]->fanslist[l] == userid) {
									flag2 = true;
									break;
								}
							}
							flag = flag1 && flag2;
						}
					}
					if (flag) {
						cout << weibolist[k]->weiboid;
						count++;
					}
					if (count == num) {
						break;
					}
				}
				cout << endl;
			}
		}
		else if (temp[0] == 'g' && temp[4] == 'o') {
			int j = 11;
			int userid = 0;
			while (temp[j] != '\0') {
				userid = userid * 10 + (temp[j] - '0');
				j++;
			}
			cout << userlist[userid]->watch << endl;
		}
		else if (temp[0] == 'g' && temp[4] == 'a') {
			int j = 8;
			int userid = 0;
			while (temp[j] != '\0') {
				userid = userid * 10 + (temp[j] - '0');
				j++;
			}
			cout << userlist[userid]->fans << endl;
		}
		else if (temp[0] == 'g' && temp[3] == 'W') {
			int j = 10;
			int userid = 0;
			while (temp[j] != '\0') {
				userid = userid * 10 + (temp[j] - '0');
				j++;
			}
			cout << userlist[userid]->weibonum << endl;
		}
		else if(temp[0] == 'f') {
			int j = 7;
			int user1id = 0;
			int user2id = 0;
			while (temp[j] != ' ') {
				user1id = user1id * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != '\0') {
				user2id = user2id * 10 + (temp[j] - '0');
				j++;
			}
			userlist[user1id]->watch++;
			userlist[user1id]->watchlist.push_back(user2id);
			userlist[user2id]->fans++;
			userlist[user2id]->fanslist.push_back(user1id);
		}
		else if (temp[0] == 'u') {
			int j = 9;
			int user1id = 0;
			int user2id = 0;
			while (temp[j] != ' ') {
				user1id = user1id * 10 + (temp[j] - '0');
				j++;
			}
			j++;
			while (temp[j] != '\0') {
				user2id = user2id * 10 + (temp[j] - '0');
				j++;
			}
			for (int k = 0; k < userlist[user1id]->watch; ++k) {
				if (userlist[user1id]->watchlist[k] == user2id) {
					for (int l = k; l < userlist[user1id]->watch - 1; ++l) {
						userlist[user1id]->watchlist[l] = userlist[user1id]->watchlist[l + 1];
					}
					userlist[user1id]->watch--;
					break;
				}
			}
			for (int k = 0; k < userlist[user2id]->fans; ++k) {
				if (userlist[user2id]->fanslist[k] == user1id) {
					for (int l = k; l < userlist[user2id]->fans - 1; ++l) {
						userlist[user2id]->fanslist[l] = userlist[user2id]->fanslist[l + 1];
					}
					userlist[user2id]->fans--;
					break;
				}
			}
		}
	}
	return 0;
}
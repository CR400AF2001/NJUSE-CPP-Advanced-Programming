#include <iostream>
#include <vector>
#include <string>
using namespace std;

class plane {
public:
	int id;
	string type;
	int up;
	int mission;
	int down;
	int uptime;
	int downtime;

	plane(){}

	plane(int thisid){
		id = thisid;
	}

	void set(int thisup, int thismission, int thisdown) {
		up = thisup;
		mission = thismission;
		down = thisdown;
	}

	void setuptime(int thisuptime) {
		uptime = thisuptime;
	}

	void setdowntime(int thisdowntime) {
		downtime = thisdowntime;
	}
};

class battleplane : public plane {
public:
	battleplane(int thisid){
		id = thisid;
		type = "battleplane";
		up = 2;
		mission = 0;
		down = 2;
	}
};

class transportplane : public plane {
public:
	transportplane(int thisid) {
		id = thisid;
		type = "transportplane";
		up = 3;
		mission = 0;
		down = 3;
	}
};

class helicopter : public plane {
public:
	helicopter(int thisid) {
		id = thisid;
		type = "helicopter";
		up = 1;
		mission = 0;
		down = 1;
	}
};

class desk {
public:
	plane* deskplane[200];
	int size;

	desk(){
		size = 0;
	}

	void add(plane* thisplane, int time) {
		deskplane[size] = thisplane;
		size++;
	}
};

int main() {
	int n = 0;
	cin >> n;
	cin.get();
	char input[100];
	plane* planelist[200];
	pair<int, plane*> uplist[200];
	pair<int, plane*> downlist[200];
	plane* upwait[200];
	plane* downwait[200];
	plane* downplanelist[200];
	pair<int, int> prioritylist[200];
	int prioritywait[200];
	int len = 0;
	int uplen = 0;
	int downlen = 0;
	int upwaitlen = 0;
	int downwaitlen = 0;
	int downplanelen = 0;
	int prioritylen = 0;
	int prioritywaitlen = 0;
	for (int i = 0; i < n; ++i) {
		cin.getline(input, 100);
		if (input[0] == 'a') {
			if (input[4] == 'b') {
				int j = 17;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				battleplane* temp = new battleplane(id);
				planelist[len] = temp;
				len++;
			}
			else if(input[4] == 't') {
				int j = 20;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				transportplane* temp = new transportplane(id);
				planelist[len] = temp;
				len++;
			}
			else if (input[4] == 'h') {
				int j = 16;
				int id = 0;
				while (input[j] != '\0') {
					id = id * 10 + (input[j] - '0');
					j++;
				}
				helicopter* temp = new helicopter(id);
				planelist[len] = temp;
				len++;
			}
		}
		else if (input[0] == 's' && input[1] == 'e') {
			int j = 5;
			int id = 0;
			while (input[j] != ' ') {
				id = id * 10 + (input[j] - '0');
				j++;
			}
			int up = 0;
			int mission = 0;
			int down = 0;
			j++;
			while (input[j] != ' ') {
				up = up * 10 + (input[j] - '0');
				j++;
			}
			j++;
			while (input[j] != ' ') {
				mission = mission * 10 + (input[j] - '0');
				j++;
			}
			j++;
			while (input[j] != '\0') {
				down = down * 10 + (input[j] - '0');
				j++;
			}
			for (int i = 0; i < len; i++) {
				if (planelist[i]->id == id) {
					planelist[i]->set(up, mission, down);
					break;
				}
			}
		}
		else if (input[0] == 'j') {
			int j = 6;
			int id = 0;
			while (input[j] != ' ') {
				id = id * 10 + (input[j] - '0');
				j++;
			}
			int time = 0;
			j++;
			while (input[j] != '\0') {
				time = time * 10 + (input[j] - '0');
				j++;
			}
			for (int i = 0; i < len; i++) {
				if (planelist[i]->id == id) {
					uplist[uplen] = pair<int, plane*>(time, planelist[i]);
					uplen++;
					break;
				}
			}
		}
		else if (input[0] == 'l') {
			int j = 10;
			int time = 0;
			int id = 0;
			while (input[j] != ' ') {
				time = time * 10 + (input[j] - '0');
				j++;
			}
			j += 2;
			while (input[j] != '\0') {
				id = id * 10 + (input[j] - '0');
				j++;
			}
			prioritylist[prioritylen] = pair<int, int>(time, id);
			prioritylen++;
		}
		else if (input[0] == 'n') {
			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					if (planelist[i]->id > planelist[j]->id) {
						plane* temp = planelist[i];
						planelist[i] = planelist[j];
						planelist[j] = temp;
					}
				}
			}
			for (int i = 0; i < len; i++) {
				cout << "p" << planelist[i]->id << " " << planelist[i]->type << " " << planelist[i]->up << " " << planelist[i]->mission << " " << planelist[i]->down;
				if (i != len - 1) {
					cout << endl;
				}
			}
		}
		else if (input[0] == 's' && input[1] == 'c') {
			for (int i = 0; i < uplen - 1; i++) {
				for (int j = i + 1; j < uplen; j++) {
					if (uplist[i].first > uplist[j].first) {
						pair<int, plane*> temp = uplist[i];
						uplist[i] = uplist[j];
						uplist[j] = temp;
					}
					else if (uplist[i].first == uplist[j].first) {
						if (uplist[i].second->type[0] == uplist[j].second->type[0]) {
							if (uplist[i].second->id > uplist[j].second->id) {
								pair<int, plane*> temp = uplist[i];
								uplist[i] = uplist[j];
								uplist[j] = temp;
							}
						}
						else if (uplist[i].second->type[0] == 't') {
							pair<int, plane*> temp = uplist[i];
							uplist[i] = uplist[j];
							uplist[j] = temp;
						}
						else if (uplist[i].second->type[0] == 'b' && uplist[j].second->type[0] == 'h') {
							pair<int, plane*> temp = uplist[i];
							uplist[i] = uplist[j];
							uplist[j] = temp;
						}
					}
				}
			}
			for (int i = 0; i < prioritylen - 1; i++) {
				for (int j = i + 1; j < prioritylen; j++) {
					if (prioritylist[i].first > prioritylist[j].first) {
						pair<int, int> temp = prioritylist[i];
						prioritylist[i] = prioritylist[j];
						prioritylist[j] = temp;
					}
				}
			}
			int clock = 0;
			int uplenindex = 0;
			int downlenindex = 0;
			int upwaitlenindex = 0;
			int downwaitlenindex = 0;
			int downplanelenindex = 0;
			int prioritylenindex = 0;
			int prioritywaitlenindex = 0;
			int occupied = 0;
			while (downplanelen < len) {
				while (prioritylenindex < prioritylen && prioritylist[prioritylenindex].first == clock) {
					prioritywait[prioritywaitlen++] = prioritylist[prioritylenindex++].second;
				}
				while (uplenindex < uplen && uplist[uplenindex].first == clock) {
					upwait[upwaitlen++] = uplist[uplenindex++].second;
				}
				while (downlenindex < downlen && downlist[downlenindex].first == clock) {
					downwait[downwaitlen++] = downlist[downlenindex++].second;
				}
				if (clock >= occupied) {
					if (prioritywaitlenindex < prioritywaitlen) {
						bool find = false;
						for (int j = downwaitlenindex; j < downwaitlen; ++j) {
							if (downwait[j]->id == prioritywait[prioritywaitlen - 1]) {
								downwait[j]->setdowntime(clock + downwait[j]->down);
								downplanelist[downplanelen++] = downwait[j];
								occupied = clock + downwait[j]->down;
								find = true;
							}
							if (find) {
								downwait[j] = downwait[j + 1];
							}
						}
						if (find) {
							downwaitlen--;
						}
						else {
							for (int j = downlenindex; j < downlen; ++j) {
								if (downlist[j].second->id == prioritywait[prioritywaitlen - 1]) {
									downlist[j].second->setdowntime(clock + downlist[j].second->down);
									downplanelist[downplanelen++] = downlist[j].second;
									occupied = clock + downlist[j].second->down;
									find = true;
								}
								if (find) {
									downlist[j] = downlist[j + 1];
								}
							}
							if (find) {
								downlen--;
							}
						}
						prioritywaitlen--;
					}
					else if (upwaitlenindex < upwaitlen) {
						upwait[upwaitlenindex]->setuptime(clock);
						int arrange = clock + upwait[upwaitlenindex]->up + upwait[upwaitlenindex]->mission;
						downlist[downlen++] = pair<int, plane*>(arrange, upwait[upwaitlenindex]);
						occupied = clock + upwait[upwaitlenindex]->up;
						upwaitlenindex++;
						for (int j = downlen - 2; j >= 0; --j) {
							if (downlist[j].first > downlist[j + 1].first) {
								pair<int, plane*> temp = downlist[j];
								downlist[j] = downlist[j + 1];
								downlist[j + 1] = temp;
							}
							else if (downlist[j].first == downlist[j + 1].first) {
								if (downlist[j].second->type[0] == downlist[j + 1].second->type[0]) {
									if (downlist[i].second->id > downlist[j].second->id) {
										pair<int, plane*> temp = downlist[j];
										downlist[j] = downlist[j + 1];
										downlist[j + 1] = temp;
									}
								}
								else if (downlist[j].second->type[0] == 'h') {
									pair<int, plane*> temp = downlist[j];
									downlist[j] = downlist[j + 1];
									downlist[j + 1] = temp;
								}
								else if (downlist[j].second->type[0] == 'b' && downlist[j + 1].second->type[0] == 't') {
									pair<int, plane*> temp = downlist[j];
									downlist[j] = downlist[j + 1];
									downlist[j + 1] = temp;
								}
							}
							else {
								break;
							}
						}
					}
					else if (downwaitlenindex < downwaitlen) {
						downwait[downwaitlenindex]->setdowntime(clock + downwait[downwaitlenindex]->down);
						downplanelist[downplanelen++] = downwait[downwaitlenindex];
						occupied = clock + downwait[downwaitlenindex]->down;
						downwaitlenindex++;
					}
				}
				clock++;
			}
			for (int i = 0; i < downplanelen; i++) {
				cout << "p" << downplanelist[i]->id << " " << downplanelist[i]->uptime << " " << downplanelist[i]->downtime;
				if (i != len - 1) {
					cout << endl;
				}
			}
		}
	}
	return 0;
}
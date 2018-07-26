// 4. The Towers of Hanoi
/* Pseudocode
// Using a buffer tower
moveDisks(int n, Tower ori, Tower dest, Tower buf) {
	if(n<=0) return;	// Base Case
	
	// Move top n-1 disks from Tower 1 to Tower 2, using Tower 3 as a buffer
	moveDisks(n-1, Tower 1, Tower 2, Tower 3);

	// move top from Tower 1 to Tower 3
	moveTop(Tower 1, Tower 3);

	// Move top n-1 disks from Tower 2 to Tower 3, using Tower 1 as a buffer
	moveDisks(n-1, Tower 2, Tower 3, Tower 1);
}
*/

#include <iostream>
#include <stack>
using namespace std;

class Tower {
public:
	Tower(int i) {
		idx = i;
	}
	~Tower() {}

	int index () { return idx; }
	void add(int d) {
		if(!disks.empty() && disks.top() <= d) {
			cout << "Error placing disk " << d << endl;
		} else {
			disks.push(d);
		}
	}

	void moveTopTo(Tower &t) {
		int top = disks.top();
		disks.pop();
		t.add(top);
		//cout << "Move Disk " << top << " from " << index() << " to " << t.index() << endl;
		printMove(top, index(), t.index());
	}

	void printMove(int disk, int from, int dest) {
		char tower_from = 'A' + from;
		char tower_to = 'A' + dest;
		cout << "Move Disk " << disk << " from " << tower_from << " to " << tower_to << endl;
	}

	void moveDisks(int n, Tower &dest, Tower &buf) {
		if(n>0) {
			moveDisks(n-1, buf, dest);
			// move top to dest
			moveTopTo(dest);
			buf.moveDisks(n-1, dest, *this);
		}
	}
private:
	stack<int> disks;
	int idx;
};

int main() {
	int n=4;
	Tower *towers[3];
	for(int i=0; i<3; i++) {
		towers[i] = new Tower(i);
	}
	for (int i=n; i>=1; --i) {
		towers[0]->add(i);
	}
	towers[0]->moveDisks(n, *towers[2], *towers[1]);

	for(int i=0; i<3; i++) {
		delete towers[i];
	}
	return 0;
}

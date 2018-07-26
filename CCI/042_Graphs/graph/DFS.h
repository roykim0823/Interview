#include <vector>
#include <iostream>
#include <stack>
#include "Graph.h"

class DepthFirstSearch
{
	vector<bool> marked;	// Mark nodes that has been explored
	vector<int> edgeTo;     // last vertex on known path to this vertex
	int source;             // starting node

	void dfs(Graph G, int v)
	{
		marked[v] = true;
		cout << "MARKED= " << v << endl;
		vector<int> temp = G.adj(v);
        vector<int>::iterator pos;
		for(pos=temp.begin(); pos !=temp.end(); ++pos)
		{  
			if(marked[*pos]==false)
			{
				edgeTo[*pos]=v;
				dfs(G, *pos);
			}
		}
	}

	// Incorrect
	void dfs2(Graph G, int v)
	{
		stack<int> s;
		marked[v]=true;
		cout << "MARKED= " << v << endl;
		s.push(v);
		while(!s.empty())
		{
			int v=s.top();
		  	//edgeTo[v] = v;
			s.pop();

			vector<int> temp = G.adj(v);
        	vector<int>::iterator pos;
			for(pos=temp.begin(); pos !=temp.end(); ++pos)
			{
				if(marked[*pos]==false)
				{
		    		edgeTo[*pos] = v;		// just for path info
					marked[*pos] = true;
					cout << "MARKED= " << *pos << endl;
					s.push(*pos);
				}
			}
		}
	}

/* JAVE varsion 1 
	public NonrecursiveDFS(Graph G, int s) {
        marked = new boolean[G.V()];

        // to be able to iterate over each adjacency list, keeping track of which
        // vertex in each adjacency list needs to be explored next
        Iterator<Integer>[] adj = (Iterator<Integer>[]) new Iterator[G.V()];
        for (int v = 0; v < G.V(); v++)
            adj[v] = G.adj(v).iterator();

        // depth-first search using an explicit stack
        Stack<Integer> stack = new Stack<Integer>();
        marked[s] = true;
        stack.push(s);
        while (!stack.isEmpty()) {
            int v = stack.peek();
            if (adj[v].hasNext()) {
                int w = adj[v].next();
                // StdOut.printf("check %d\n", w);
                if (!marked[w]) {
                    // discovered vertex w for the first time
                    marked[w] = true;
                    // edgeTo[w] = v;
                    stack.push(w);
                    // StdOut.printf("dfs(%d)\n", w);
                }
            }
            else {
                // StdOut.printf("%d done\n", v);
                stack.pop();
            }
        }
    }
*/

/* Jave version2
Here is an alternate implementation suggested by Bin Jiang in the early 1990s. The only extra memory is for a stack of vertices but that stack must support arbitrary deletion (or at least the movement of an arbitrary item to the top of the stack).

private void dfs(Graph G, int s) {
    SuperStack<Integer> stack = new SuperStack<Integer>();
    stack.push(s);
    while (!stack.isEmpty()) {
        int v = stack.peek();
        if (!marked[v]) {
            marked[v] = true;
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    if (stack.contains(w)) stack.delete(w);	// stack deletion is not normal stack operation
                    stack.push(w);
                }
            }
        }
        else {
            // v's adjacency list is exhausted
            stack.pop();
        }
    }
}
*/

	void dfs_iterative(Graph G, int v)
	{
		stack<int> s;
		s.push(v);
		marked[v]=true;
		cout << "MARKED= " << v << endl;
		while(!s.empty())
		{
			int v=s.top(); 	// peek stack top

			vector<int> temp = G.adj(v);
        	vector<int>::iterator pos;
			bool m=false;
			for(pos=temp.begin(); pos !=temp.end(); ++pos) {
			  	if(marked[*pos]==false) {	// visiting new node
			   		marked[*pos]=true;
					cout << "MARKED= " << *pos << endl;
		       		edgeTo[*pos] = v;		// just for path info
			   		s.push(*pos);       	// push the new node on the stack
					m=true;
					break;                  // new node found then stop the search
				}
			}
			if(m==false)                   	// Not found new node
				s.pop();                    // pop the node on the stack

		}
	}

	// Correct but reverse order
	// It is simplest implementation, but is uses space proportional to E+V in the worst case
	// because more than one copy of a vertex can be on the stack
	// And, it explores the vertices adjacent to v in the reverse order of the standard recursive
	// DFS. Also edgeTo[v] entry may be updated more than once.
	// -> So, it may not be suitable for backtracking applications
	void dfs_iterative2(Graph G, int v)
	{
		stack<int> s;
		s.push(v);
		while(!s.empty())
		{
			int v=s.top();
			s.pop();

			if(marked[v]==false) {
				marked[v]=true;
				cout << "MARKED= " << v << endl;

				vector<int> temp = G.adj(v);
        		vector<int>::iterator pos;
				for(pos=temp.begin(); pos !=temp.end(); ++pos)
					if(marked[*pos]==false) {
		    			edgeTo[*pos] = v;		// just for path info
						s.push(*pos);
					}
			}
		}
	}

public:
	DepthFirstSearch(Graph G, int s=0)
	{
		marked.resize(G.get_V());
		edgeTo.resize(G.get_V());
		source = s;
		dfs(G, s);
		//dfs2(G, s);
		//dfs_iterative(G, s);
		//dfs_iterative2(G, s);
	}

	bool hasPathTo(int v) 	// return true if there a path from s to v
	{ return marked[v]; }

	stack<int> pathTo(int v)	// return path from s to v; null if no such path
	{
		stack<int> path;
		if(hasPathTo(v)==false) return path;
		for(int x=v; x !=source; x=edgeTo[x])
			path.push(x);
		path.push(source);
		return path;
	}

};

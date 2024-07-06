package DFS;

import java.util.LinkedList;
import java.util.Stack;

public class DFSTraversal {
    private LinkedList<Integer>adj[];
    private boolean visitedVertex[];

    void insertEdge(int source, int destination){
        this.adj[source].add(destination);
    }

    void DFS(int startingVertex){
        Stack<Integer> stack = new Stack<>();
        stack.push(startingVertex);

        while(!stack.isEmpty()){
            int vertex = stack.pop();
            if (!visitedVertex[vertex]){
                visitedVertex[vertex] = true;
                System.out.print(vertex+" ");
                for(Integer neighbour: adj[vertex]){
                    if (!visitedVertex[neighbour]){
                        stack.push(neighbour);
                    }
                };
            }
        }
    }
    DFSTraversal(int numberOfvertex){
        this.adj = new LinkedList[numberOfvertex];
        this.visitedVertex= new boolean [numberOfvertex];
        for(int i=0; i<numberOfvertex;i++)
            this.adj[i] = new LinkedList<Integer>();
    }
    public static void main(String[] args) {
        DFSTraversal graph = new DFSTraversal(8);

        graph.insertEdge(0,2);
        graph.insertEdge(0,3);
        graph.insertEdge(1,2);
        graph.insertEdge(4,5);
        graph.insertEdge(2,3);

        graph.DFS(0);
    }
}

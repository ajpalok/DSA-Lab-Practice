package BFS;

import java.util.LinkedList;

public class BFSTraversal {
    private int V;
    private LinkedList<Integer> adjLists[];

    BFSTraversal(int v){
        this.V = v;
        this.adjLists = new LinkedList[v];
        for (int i=0; i<v; i++) adjLists[i] = new LinkedList<>();
    }

    void addEdge(int v, int w){
        this.adjLists[v].add(w);
    }

    void BFS(int s){

    }

    public static void main(String[] args) {
        BFSTraversal g = new BFSTraversal(4);
    }
}

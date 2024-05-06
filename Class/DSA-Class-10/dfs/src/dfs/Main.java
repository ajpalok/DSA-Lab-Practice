package dfs;

import java.util.Arrays;

class Main {
    static int[][] vertArr = new int[20][20]; // the adjacency matrix initially 0

    static void displayMatrix(int v) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                System.out.print(vertArr[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void add_edge(int u, int v) {
        vertArr[u][v] = 1;
        vertArr[v][u] = 1;
    }

    public static void main(String[] args) {
        int v = 6; // there are 6 vertices in the graph
        add_edge(0, 4);
        add_edge(0, 3);
        add_edge(1, 2);
        add_edge(1, 4);
        add_edge(1, 5);
        add_edge(2, 3);
        add_edge(2, 5);
        add_edge(5, 3);
        add_edge(5, 4);
        displayMatrix(v);
    }
}

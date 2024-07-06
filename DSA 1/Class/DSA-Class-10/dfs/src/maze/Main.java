package maze;

import java.util.LinkedList;
import java.util.Queue;

class Main {
    static int[][] maze = {
            {0, 1, 1, 0, 2},
            {0, 1, 1, 0, 1},
            {0, 1, 1, 0, 1},
            {0, 0, 0, 0, 1}
    };

    static int[][] visited = new int[4][5];

    static void dfs(int row, int col) {
        if (row < 0 || row > 3 || col < 0 || col > 4) return;

        System.out.println(row + " " + col);
        if (maze[row][col] == 2) System.out.println("We are in the exit");

        visited[row][col] = 1;
        if (col + 1 < 5 && maze[row][col + 1] != 1 && visited[row][col + 1] == 0) {
            dfs(row, col + 1);
        }
        if (col - 1 >= 0 && maze[row][col - 1] != 1 && visited[row][col - 1] == 0) {
            dfs(row, col - 1);
        }
        if (row + 1 < 4 && maze[row + 1][col] != 1 && visited[row + 1][col] == 0) {
            dfs(row + 1, col);
        }
        if (row - 1 >= 0 && maze[row - 1][col] != 1 && visited[row - 1][col] == 0) {
            dfs(row - 1, col);
        }
        visited[row][col] = 0;
    }

    public static void main(String[] args) {
        dfs(3, 0);
    }
}

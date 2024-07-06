// MARK: Question 2 : The Maze of Mysteries - Finding Paths with Treasures
// 
// You find yourself in a mysterious maze filled with twists and turns, dead ends, and hidden treasures. Your task is to navigate through the maze to find paths from the starting position to the exit that contain hidden treasures. The maze is represented as a 2D grid where each cell can have the following values:
// 
// 0: Pathway.
// 1: Wall.
// 2: Exit.
// 3: Treasure.

// You have to take the maze size as input as well as the above values for that maze cell.
// Write a function find_paths_with_treasures(maze, start_row, start_col) that takes the maze grid and your starting position as inputs. The function should print all the paths from the starting position to the exit (2) that contain treasures (3). If no such path is possible, the function should print "No path with treasure found." 

// Here is a sample maze with a size of 5x5:
// maze = [
//     [0, 1, 2, 0, 0],
//     [0, 0, 0, 1, 0],
//     [0, 3, 1, 0, 0],
//     [0, 1, 0, 1, 0],
//     [0, 0, 0, 0, 0]
// ]
//For the given maze and starting position (0, 0), the function should print the following path:
// Path with treasure: (0, 0) -> (1, 0) -> (2, 0) -> (2, 1) -> (1, 1) -> (1, 2) -> (0, 2) 

// In this case, the path starts from the treasure at position (0, 0), follows the pathway, and ends at the exit (2) while collecting the treasure on the way.

// Your function should implement either BFS or DFS to explore the maze, avoid walls (1), and identify paths containing treasures. If no such path is found, the function should print "No path with treasure found."

// Here is a sample maze with a size of 5x5:
// maze = [
//     [0, 1, 0, 0, 2],
//     [0, 0, 0, 1, 0],
//     [0, 3, 1, 0, 0],
//     [0, 1, 0, 1, 0],
//     [0, 0, 0, 0, 0]
// ]
// For this maze and starting position (1, 0), the function should print:

// Path with treasure: (1, 0) -> (2, 0) -> (2, 1) -> (1, 1) -> (1, 2) ->(0,2) -> (0, 3) ->(0,4)
// Path with treasure: (1, 0) -> (1, 1) -> (2, 1) -> (2, 0) -> (3, 0) ->(4,0) -> (4, 1) ->(4, 2)

// -> (4, 3) ->(4, 4) -> (3, 4) ->(2, 4) -> (1, 4) ->(0,4)

// Bonus Challenge Question: pointing out shortest path ( Mark 1) : implement strategy for pointing out the shortest path . In the above example 1st path is the shortest.

// Using BFS we will solve this problem.


// MARK: Start of the code

import java.util.Scanner;

public class MazeSolver{
    // initialize size of maze and visited array from the input
    int rows, cols;
    int[][] maze;
    int[][] visited;
    // initialize the start position
    int startRow, startCol;

    // constructor to initialize the maze and visited array
    MazeSolver(int rows, int cols, int[][] maze, int startRow, int startCol){
        this.rows = rows;
        this.cols = cols;
        this.startRow = startRow;
        this.startCol = startCol;
        this.maze = maze;
        visited = new int[rows][cols];
    }
    
    // function to check if the move is valid
    boolean isValidMove(int row, int col){
        return  row >= 0 &&
                row < rows &&
                col >= 0 && col < cols &&
                maze[row][col] != 1;
    }

    // function to find the path with treasures. after starting from the given position and after visiting the treasure, go to exit
    void findPaths(int row, int col, String path){
        if(!isValidMove(row, col) || visited[row][col] == 1){
            return;
        }

        visited[row][col] = 1;

        if(maze[row][col] == 3){
            path += " -> (" + row + ", " + col + ")";
        }

        if(maze[row][col] == 2){
            path += " -> (" + row + ", " + col + ")";
            if(path.contains("3")){
                System.out.println("Path with treasure: " + path);
            }
            visited[row][col] = 0;
            return;
        }

        findPaths(row + 1, col, path + " -> (" + row + ", " + col + ")");
        findPaths(row - 1, col, path + " -> (" + row + ", " + col + ")");
        findPaths(row, col + 1, path + " -> (" + row + ", " + col + ")");
        findPaths(row, col - 1, path + " -> (" + row + ", " + col + ")");

        visited[row][col] = 0;
    }

    // function to start the path finding process
    void findPaths(){
        findPaths(startRow, startCol, "");
    }


    public static void main(String[] args){
        // int rows = 5;
        // int cols = 5;
        // int[][] maze = {
        //     {0, 1, 0, 0, 2},
        //     {0, 0, 0, 1, 0},
        //     {0, 3, 1, 0, 0},
        //     {0, 1, 0, 1, 0},
        //     {0, 0, 0, 0, 0}
        // 0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 3, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0
        // };
        // int startRow = 1;
        // int startCol = 0;

        // MazeSolver mazeSolver = new MazeSolver(rows, cols, maze, startRow, startCol);
        // mazeSolver.findPaths();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = scanner.nextInt();

        int[][] maze = new int[rows][cols];
        System.out.println("Enter maze elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }

        System.out.print("Enter starting row: ");
        int startRow = scanner.nextInt();
        System.out.print("Enter starting column: ");
        int startCol = scanner.nextInt();

        MazeSolver mazeSolver = new MazeSolver(rows, cols, maze, startRow, startCol);
        mazeSolver.findPaths();

        scanner.close();
    }
}

// MARK: input

/*
 * 
 * 5 5 0 1 0 0 2 0 0 0 1 0 3 1 0 0 0 1 0 1 0 1 0 0 0 0 0 1 0 0 2 0 0 0 1 0 0 0 1 0 3 1 0 0 0 1 0 1 0 1 0 0 0 0 0 1
*/
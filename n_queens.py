# See notes/backtracking.md

N = 8


def solve(board) -> int:
    return try_to_place(board, 0)


def try_to_place(board, i) -> int:
    num_solutions = 0
    for j in range(N):
        if ok_to_place(board, i, j):
            board[i][j] = 1
            if i == N - 1:
                display_board(board)
                board[i][j] = 0  # backtrack (unset the queen)
                return 1
            num_solutions += try_to_place(board, i + 1)  # recursion
            board[i][j] = 0  # backtrack (unset the queen)
    return num_solutions


def ok_to_place(board, i, j) -> bool:
    # vertical
    row = i - 1
    col = j
    while row >= 0:
        if board[row][col] == 1:
            return False
        row -= 1

    # diagonal up-left
    row = i - 1
    col = j - 1
    while row >= 0 and col >= 0:
        if board[row][col] == 1:
            return False
        row -= 1
        col -= 1

    # diagonal up-right
    row = i - 1
    col = j + 1
    while row >= 0 and col < N:
        if board[row][col] == 1:
            return False
        row -= 1
        col += 1

    return True


def display_board(board) -> None:
    for row in board:
        print(" ".join(str(x) for x in row))
    print("-" * (2 * N - 1))


if __name__ == "__main__":
    board = [[0] * N for _ in range(N)]
    num_solutions = solve(board=board)
    print(f"Number of solutions: {num_solutions}")

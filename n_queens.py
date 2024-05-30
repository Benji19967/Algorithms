N = 8


def solve(board, num_solutions) -> int:
    return try_to_place(board, 0, num_solutions)


def try_to_place(board, i, num_solutions) -> int:
    for j in range(N):
        if ok_to_place(board, i, j):
            board[i][j] = 1
            if i == N - 1:
                display_board(board)
                board[i][j] = 0  # backtrack (unset the queen)
                return num_solutions + 1
            num_solutions = try_to_place(board, i + 1, num_solutions)  # recursion
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

    # diagonal top-left
    row = i - 1
    col = j - 1
    while row >= 0 and col >= 0:
        if board[row][col] == 1:
            return False
        row -= 1
        col -= 1

    # diagonal top-right
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
    num_solutions = 0
    board = [[0] * N for _ in range(N)]
    num_solutions = solve(board=board, num_solutions=num_solutions)
    print(f"Number of solutions: {num_solutions}")

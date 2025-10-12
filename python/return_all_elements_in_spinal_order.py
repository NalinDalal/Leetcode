#Given an m x n matrix, return all elements of the matrix in spiral order.

def spiralOrder(matrix):
    res = []
    while matrix:
        # Add the first row
        res += matrix[0]
        matrix.pop(0)

        # Add the last element of each remaining row
        if matrix and matrix[0]:
            for row in matrix:
                res.append(row.pop())

        # Add the last row in reverse order
        if matrix:
            res += matrix[-1][::-1]
            matrix.pop()

        # Add the first element of each remaining row (bottom to top)
        if matrix and matrix[0]:
            for row in matrix[::-1]:
                res.append(row.pop(0))

    return res


# Example
matrix = [[1,2,3],[4,5,6],[7,8,9]]
print(spiralOrder(matrix))
# Output: [1,2,3,6,9,8,7,4,5]

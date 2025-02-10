# math.flex

# Function to calculate the square of a number
function square(x) {
    return x * x
}

# Function to calculate the cube of a number
function cube(x) {
    return x * x * x
}

# Function to calculate the factorial of a number
function factorial(n) {
    if (n == 0 || n == 1) {
        return 1
    } else {
        return n * factorial(n - 1)
    }
}

# Function to calculate the power of a number (x^y)
function power(x, y) {
    result = 1
    for i = 1 to y
        result = result * x
    endfor
    return result
}

# Function to calculate the greatest common divisor (GCD) of two numbers
function gcd(a, b) {
    while b != 0
        temp = b
        b = a % b
        a = temp
    endwhile
    return a
}

# example_with_module.flex

#include "modules/math.flex"

var a = 5
var b = 3
var message = "Using modules!"

print "Message: "
print message

print "a squared is:"
print square(a)

print "b cubed is:"
print cube(b)

print "Factorial of a is:"
print factorial(a)

print "5 to the power of 3 is:"
print power(5, 3)

print "GCD of 48 and 18 is:"
print gcd(48, 18)

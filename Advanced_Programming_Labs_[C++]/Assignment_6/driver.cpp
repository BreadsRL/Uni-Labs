#include <igloo/igloo.h>
#include "lab6.h"
#include <iomanip>

using namespace igloo;


Context(Lab6stuff) {
    
    Spec(Singleton) {
        std::vector<int> numbersA { 1, 2, 3, 1, 3 };
        std::vector<int> numbersB { 1 };
        std::vector<int> numbersC { 1, -5, 2, 2, -6, 1, 5, 5, -5 };
        Assert::That(singleton(numbersA), Equals(2));
        Assert::That(singleton(numbersB), Equals(1));
        Assert::That(singleton(numbersC), Equals(-6));
    }

    
    Spec(Missing) {
        std::vector<int> numbersA { 1, 2, 3 };
        std::vector<int> numbersB { 0, 1, 3 };
        std::vector<int> numbersC { 0, 1, 2 };
        Assert::That(missing(numbersA), Equals(0));
        Assert::That(missing(numbersB), Equals(2));
        Assert::That(missing(numbersC), Equals(3));
    }

    
    Spec(ContainsDuplicate) {
        std::vector<int> numbersA { 1, 2, 3, 4, 5 };
        std::vector<int> numbersB { 1, 2, 1, 3, 4 };
        Assert::That(containsDuplicate(numbersA), IsFalse());
        Assert::That(containsDuplicate(numbersB), IsTrue());
    }

    
    Spec(Compress) {
        std::vector<int> numbersA { 1, 2, 3, 4, 5, 6 };
        std::vector<int> outputA { 1, 6 };

        std::vector<int> numbersB { 1, 2, 3, 5, 6, 7 };
        std::vector<int> outputB { 1, 3, 5, 7 };

        std::vector<int> numbersC { 1, 2, 3, 5, 7, 8 };
        std::vector<int> outputC { 1, 3, 5, 5, 7, 8 };

        Assert::That(compress(numbersA), Equals(outputA));
        Assert::That(compress(numbersB), Equals(outputB));
        Assert::That(compress(numbersC), Equals(outputC));
    }

    Spec(Decompress) {
        std::vector<int> numbers { 1, 3, 5, 7 };
        std::vector<int> output { 1, 2, 3, 5, 6, 7 };
        Assert::That(decompress(numbers), Equals(output));
        
    }

    Spec(DetectError) {
        std::vector<int> numbers { 1, 2, 5, 4, 5, 6 };
        Assert::That(detectError(numbers), Equals(3));
    }
};

int main() {
    std::cout << std::boolalpha << std::setprecision(17);
    return TestRunner::RunAllTests();
}

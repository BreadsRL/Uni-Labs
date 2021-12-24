#include <igloo/igloo.h>
#include "lab5.h"

using namespace igloo;


Context(CountVowelsTest){
    //Count Vowels Test
    Spec(OneAVowel){
        Assert::That(countVowels("xxxxaxxxx"), Equals(1));
    }
    Spec(OneEVowel){
        Assert::That(countVowels("xxxxexxxx"), Equals(1));
    }
    Spec(OneIVowel){
        Assert::That(countVowels("xxxxixxxx"), Equals(1));
    }
    Spec(OneOVowel){
        Assert::That(countVowels("xxxxoxxxx"), Equals(1));
    }
    Spec(OneAUVowel){
        Assert::That(countVowels("xxxxuxxxx"), Equals(1));
    }
    Spec(AllVowels){
        Assert::That(countVowels("xaeioux"), Equals(5));
    }
    Spec(NoVowels){
        Assert::That(countVowels("bcdfghjklmnpqrstvwxyz"), Equals(0));
    }
    Spec(AllVowelsUppercase){
        Assert::That(countVowels("xAxExIxOxUx"), Equals(5));
    }
    Spec(EmptyString){
        Assert::That(countVowels(""), Equals(0));
    }
};

Context(StringStabilityTest){
    //String Stability Test
    Spec(Length4EqualVowels){
        Assert::That(isStable("abba"), IsTrue());
    }
    Spec(Length4UneualVowels){
        Assert::That(isStable("abxx"), IsFalse());
    }
    Spec(Length4NoVowels){
        Assert::That(isStable("xxxx"), IsTrue());
    }
    Spec(Length7EqualVowels){
        Assert::That(isStable("iuxexao"), IsTrue());
    }
    Spec(Length7UnequalVowels){
        Assert::That(isStable("iuxexxx"), IsFalse());
    }
    Spec(EmptyString){
        Assert::That(isStable(""), IsTrue());
    }
};

Context(DoubleLetterTest){ 
    //Test for Double Letters
    Spec(DoubleHMiddle){
        Assert::That(hasDoubleLetters("abchhdef"), IsTrue());
    }
    Spec(DoubleHEnd){
        Assert::That(hasDoubleLetters("abcdefhh"), IsTrue());
    }
    Spec(DoubleHStart){
        Assert::That(hasDoubleLetters("hhabcdef"), IsTrue());
    }
    Spec(NoDoubleLetters){
        Assert::That(hasDoubleLetters("abcdefgh"), IsFalse());
    }
    Spec(EmptyString){
        Assert::That(hasDoubleLetters(""), IsFalse());
    }
};
Context(InterleavingWordsTest){
    //Interleaving words Test
    Spec(_135and246){
        Assert::That(interleave("135","246"), Equals("123456"));
    }
    Spec(HelloandWorld){
        Assert::That(interleave("Hello","World"), Equals("HWeolrllod"));
    }
    Spec(ComputerandScience){
        Assert::That(interleave("Computer","Science"), Equals("CSocmipeuntceer"));
    }
    Spec(CheeseandCake){
        Assert::That(interleave("Cheese","Cake"), Equals("CChaekeese"));
    }
    Spec(HelloandEmptyString){
        Assert::That(interleave("Hello",""), Equals("Hello"));
    }
    Spec(EmptyStringandHello){
        Assert::That(interleave("","Hello"), Equals("Hello"));
    }
    Spec(EmptyStringandEmptyString){
        Assert::That(interleave("",""), Equals(""));
    }
};
Context(CommonPrefixTest){ 
    //Common Prefix Test
    Spec(HelloandHelp){
        Assert::That(lcp("Hello","Help"), Equals("Hel"));
    }
    Spec(WhaleandWhale){
        Assert::That(lcp("Whale","Whale"), Equals("Whale"));
    }
    Spec(HappyandSad){
        Assert::That(lcp("Happy","Sad"), Equals(""));
    }
    Spec(HappyandEmptyString){
        Assert::That(lcp("Happy",""), Equals(""));
    }
    Spec(EmptyStringandSad){
        Assert::That(lcp("","Sad"), Equals(""));
    }
    Spec(EmptyStringandEmptyString){
        Assert::That(lcp("",""), Equals(""));
    }
};

Context(CatCoursesSpreadsheetTest){
    //CatCourses Spreadsheet test
    Spec(SteveJobs){
        Assert::That(extractLastName("Steve Jobs","sjobs@ucmerced.edu"), Equals("Jobs"));
    }
    Spec(SteveJobswithnumbers){
        Assert::That(extractLastName("Steve Jobs","sjobs3434@ucmerced.edu"), Equals("Jobs"));
    }
};


int main(){
    return TestRunner::RunAllTests();
}

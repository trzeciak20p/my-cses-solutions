
void IntroAndBody(){

    // Lambda najczęsciej składa się z 3 częsci - [](){}
    // nawiasy klamrowe są jednak opcjonalne i narazie będziemy je pomijać

    // Narazie skupimy się na klamrowych nawiasach, które są ciałem lambdy
    // Jest to miejsce kod który lambda ma wykonać
    []{
        int x = 0;
        x = 2;
    };
    // Lamda tworzy własny scope więc zmiennych deklarowanych w środku nie można używać poza nią


    // użycie return - sprawi że lambda zwróci wartość
    []{
        int x = 2;
        return x;
    };
    // jeśli chcemy określić jaki typ zwraca lambda robimy to umieszczając "-> typzmiennej" przed nawiasami klamrowymi

    // []()->bool{
    //     return true;
    // };

    // Każda wyżej napisana lambda jest anonimowa (nie przypisaliśmy jej do żadnej zmiennej)

    // Lambdy można przypisywać do zmiennych
    auto f = []{
        return 1;
    };

    // dajemy typ auto ponieważ lambda zwracająca wartość nie jest tą wartością sama w sobie
    int g = []{       // BŁĄD - no suitable conversion function from "lambda []()->int" to "int"
        return 2;
    };

    // Aby wywołać lambde dajemy za niż nawiasy
    int x = f();

    // Działa to też z anonimowymi lambdami
    int g = []{
        return 2;
    }();
    // Naprawia to błąd z przedtem ponieważ teraz do zmiennej g przypisujemy nie lambde, a wartość którą ona zwraca
}


void CaptureClause(){   // idk jak to na pl
    int y = 0;
    int x = 0;

    // Klauzula przechwytwania XD
    // Domyślnie w ciele lambdy nie można używać zmiennych z poza jej scope-u
    x = []{
        return y;   // BŁĄD - nie mamy dostępu do y
    }();

    // Aby to zmienić musimy wrzucić zmienną której chcemy użyć do []
    x = [y]{    
        return y;   // możemy używać wartości y
    }();

    // [=] mówi, że przekazujemy wartość każdej zmiennej jaka pojawi się w ciele lambdy
    int z = 2;
    x = [=]{
        return y + z;
    }();


    // Problem pojawia się jeśli zmienną z zewnątrz chcialibyśmy edytować
    x = [y]{   
        y = 2;      // BŁĄD - przekazujemy tylko warość zmiennej y (Lvalue) więc nie może ona zostać zmieniona (readonly)
        return y;
    }();

    // Tu z pomocą przychodzi referencja
    x = [&y]{   
        y = 2;      // można edytować, y zmienia się też na zewnątrz!
        return y;
    }();

    // [&] mówi, że każdą zmienną z zewnątrz przekazujemy jako referencje
    x = [&]{   
        y = 2;
        z = 3;     
        return y * z;
    }();

    // [=] lub [&] mówią o tym jak każda zmienna będzie traktowana domyślnie
    // można to jednak nadpisać
    x = [&, z]{   
        y = 2;      // y jest brana domyślnie jako referencja 
        z = 3;      // BŁĄD - z jest brana tylko wartość
        return y * z;
    }();

    // Odwrotny przypadek
    x = [=, &z]{   
        y = 2;      // BŁĄD - y jest brana domyślnie jako wartość
        z = 3;      // z jest brana jako referencja 
        return y * z;
    }();
}

void ParameterList(){

    // Teraz skupimy się na liście parametrów, czyli okrągłych nawiasach
    // Tak samo jak przy funkcjach, służą do przekazywania argumentów przy wywoływaniu
    auto f = [](int a){
        return a + 1;
    };
    // Przy wywoływaniu przekazujemy wartość
    int x = f(3);

    // Argumentami mogą być wskażniki i referencje
    auto f2 = [](int &a, char *c){
        a = 2;
        *c = a;
    };

    // Na pierwszy rzut oka lista parametrów wydaje się bardzo podobna do klauzuli przejęcia, różnią się jednak
    // Klauzula zawsze odnosi się do tej samej zmiennej, kiedy w argumentach można przekazać jakąkolwiek zmienną/wartość
}

int main(int argc, char const *argv[])
{
    return 0;
}

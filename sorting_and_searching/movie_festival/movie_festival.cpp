#include <iostream>

struct t_movie{
    int start;
    int end;
};

int main(int argc, char const *argv[])
{
    int n = 0;
    std::cin >> n;
    t_movie movies[n]{};
    for (int i = 0; i < n; i++)
    {
        std::cin >> movies[n].start;
        std::cin >> movies[n].end;
    }
    int max_movies = 0;



    std::cout << max_movies << "\r\n";

    return 0;
}

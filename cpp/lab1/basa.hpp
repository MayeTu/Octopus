#include "vector.hpp"

class Basa
{
private:
    Vector items;
public:
    void load (ifstream& file);
    void unload(ofstream& file);
    void work();
};

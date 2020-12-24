#include "eigen/Dense"

#include <iostream>


int main() {

    Eigen::Vector2f v1;//(3,5);
    Eigen::Vector2f v2;//(300, 800);
    Eigen::Matrix<float, 2, 1> m;//(300, 800);

    v1(3, 5);
    std::cout << "vector2f small" << std::endl;
    std::cout << v1 << std::endl;

    v2(300, 800);
    std::cout << "vector2f large" << std::endl;
    std::cout << v2 << std::endl;

    m(300, 800);
    std::cout << "matrix" << std::endl;
    std::cout << m << std::endl;
    return 0;

}

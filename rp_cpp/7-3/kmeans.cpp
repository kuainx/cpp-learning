#include "kmeans.hpp"

double Point::Distance(Point& other)
{
    // YOUR CODE HERE
}

std::istream& operator>>(std::istream& is, Point& pt)
{
    // YOUR CODE HERE
}

std::ostream& operator<<(std::ostream& os, Point& pt)
{
    // YOUR CODE HERE
}


Kmeans::Kmeans(const std::vector<Point>& points, const std::vector<Point>& initialCenters)
{
    // YOUR CODE HERE
}

std::vector<index_t> Kmeans::Run(int maxIterations)
{
    // DO NOT MODIFY THESE CODE
    std::vector<index_t> assignment(m_numPoints, 0); // the return vector
    int currIteration = 0;
    std::cout << "Running kmeans with num points = " << m_numPoints 
            << ", num centers = " << m_numCenters 
            << ", max iterations = " << maxIterations << "...\n";

    // YOUR CODE HERE


    // YOUR CODE ENDS HERE
    std::cout << "Finished in " << currIteration << " iterations." << std::endl;
    return assignment;
}
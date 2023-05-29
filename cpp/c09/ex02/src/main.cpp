/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:10:16 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 20:10:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char **argv)
{
   
    if (argc <= 2)
        return (1);
    PmergeMe vector;
    try
    {
        if (vector.parser_arguments(++argv) == 1)
            return (0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
    struct timeval start, ends;

    std::cout << "BEFORE ";
    vector.printContainer(vector.getVector());
    
    gettimeofday(&start, NULL);
    vector.mergeInsert(vector.getVector(), vector.getVector().begin(), --vector.getVector().end());
    gettimeofday(&ends, NULL);
    std::cout << "AFTER ";
    vector.printContainer(vector.getVector());
    double elapsed_time = (ends.tv_sec - start.tv_sec) + (ends.tv_usec - start.tv_usec) / 1000000.0;
    std::cout << std::fixed << std::setprecision(6) << "Time to process a range of     " << vector.getVector().size() << " elements with std::vector<int> "  << elapsed_time << " us\n";
    
    gettimeofday(&start, NULL);
    vector.mergeInsert(vector.getDeque(), vector.getDeque().begin(), --vector.getDeque().end());
    gettimeofday(&ends, NULL);
    elapsed_time = (ends.tv_sec - start.tv_sec) + (ends.tv_usec - start.tv_usec) / 1000000.0;
    std::cout <<  std::fixed << std::setprecision(6) << "Time to process a range of     " << vector.getDeque().size() << " elements with std::deque<int> "  << elapsed_time << " us\n";
    
    return 0;
}

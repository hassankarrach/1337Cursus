/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:09:27 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:59:19 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static void replaceString(std::string &content, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: The string to replace cannot be empty.\n";
        return;
    }

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: replace <file> old_word new_word\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Failed to open the file.\n";
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(infile, line))
        content += line + "\n";
    infile.close();

    replaceString(content, s1, s2);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Failed to open the output file.\n";
        return 1;
    }
    
    outputFile << content;
    outputFile.close();

    return 0;
}

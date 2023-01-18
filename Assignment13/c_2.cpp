#include<bits/stdc++.h>

// Structure to store the city data
struct City
{
    std::string name;
    double temperature;
    char metric;
};

// Function to compare two cities based on their temperature
bool compareCities(City a, City b)
{
    // If the metrics are different, convert b's temperature to a's metric
    if (a.metric != b.metric)
    {
        if (a.metric == 'C')
        {
            b.temperature = (b.temperature - 32) * 5 / 9;
        }
        else
        {
            b.temperature = b.temperature * 9 / 5 + 32;
        }
    }

    // Compare the temperatures
    if (a.temperature != b.temperature)
    {
        return a.temperature < b.temperature;
    }
    else
    {
        // If the temperatures are equal, compare the names
        return a.name < b.name;
    }
}

int main()
{
    // Read the data from the input file
    std::ifstream input("testdata.in");
    std::vector<City> cities;
    std::string line;
    while (std::getline(input, line))
    {
        std::istringstream iss(line);
        std::string city, temp, metric;
        std::getline(iss, city, '#');
        std::getline(iss, temp, '#');
        std::getline(iss, metric, '#');
        City c = { city, std::stod(temp), metric[0] };
        cities.push_back(c);
    }

    // Sort the cities
    std::sort(cities.begin(), cities.end(), compareCities);

    // Output the sorted cities
    for (const auto& city : cities)
    {
        printf("%s is %.2f%c\n", city.name.c_str(), city.temperature, city.metric);
    }

    return 0;
}

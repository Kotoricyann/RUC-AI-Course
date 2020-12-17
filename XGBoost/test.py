def main():
    CountryList = []
    Population = []
    read_data(CountryList,Population)
    print(CountryList)
    str = input('input:')
    FindList = str.split('/')
    print(sum_users_countries(CountryList, Population, FindList))


class CountryPopu:
    def _init_(self, name, population):
        self.name = name
        self.population = population


def read_data(CountryList,Population):
    inFile = open('countries.txt','r')
    text = inFile.read()
    inFile.close()  
    text = text.split(',')
    #print(text)
    i = 0
    while(i < len(text)):
        CountryList.append(text[i]) 
        Population.append(text[i+1]) 
        i = i+2


def sum_users_countries(CountryList, Population, FindList):
    PopuSum=0
    for i in range(len(FindList)):
        index = CountryList.index(FindList[i], 0, len(CountryList))
        PopuSum = PopuSum + float(Population[index])
    return PopuSum

main()
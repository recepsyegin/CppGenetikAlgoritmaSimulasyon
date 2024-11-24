#include <bits/stdc++.h>
using namespace std;
#define SUCCESS 0

// Her nesil için popülasyon sayýsý
#define POPULATION_SIZE 100

// Genler
const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP" 
"QRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

// Hedef string
const string HEDEF = "Genetik Algoritma Github Ornek";

// Verilen aralikta rastgele sayi uretmek icin gerekli fonksiyon:
int random_num(int start,int end)
{
	int range = ((end - start) + 1);
	int random_int = start + (rand() % range);
	return random_int;
}

// Mutasyon olayi icin rastgele gen olusturma
// Rastgele secip donduruyoruz
char mutated_genes()
{
	int len = GENES.size();
	int r = random_num(0,len-1);
	return GENES[r];
}

// Hedefimizin uzunlugunda string olusturalim (kromozom)
string create_genome()
{
	int len = HEDEF.size();
	string genom = "";
	for(int i = 0; i < len; ++i)
	{
		genom += mutated_genes();
	}
	return genom;
}

// Popülasyondaki her bir çözüm " individual " için class
class Individual{
	public:
		string chromosome;
		int fitness;
		Individual(string chromosome);
		Individual mate(Individual parent2);
		int calculate_fitness();
};

Individual::Individual(string chromosome)
{
	this->chromosome = chromosome;
	fitness = calculate_fitness();
};

// Yavrularimizi olusturalim
Individual Individual::mate(Individual parent2)
{
	string child_chromosome = "";
	int len = chromosome.size();
	
	for(int i = 0; i < len; ++i)
	{
		float p = random_num(0,100) / 100.0;
		if( p < 0.45)
		{
			child_chromosome += chromosome[i];
		}
		else if( p < 0.90)
		{
			child_chromosome += parent2.chromosome[i];
		}
		else
		{
			child_chromosome += mutated_genes();
		}
	}
	return Individual(child_chromosome);	
};

// Fitness degeri hesaplama:
int Individual::calculate_fitness()
{
	int len = HEDEF.size();
	int fitness = 0;
	for(int i = 0; i < len; ++i)
	{
		if(chromosome[i] != HEDEF[i])
			fitness++;
	}
	return fitness;
}

// Ebeveynlerin fitness degerini karsilastirmak icin < operatorunu overload edelim
bool operator<(const Individual &ind1, const Individual &ind2)
{
	return ind1.fitness < ind2.fitness;
}

// Kosturan kod - driver -
int main()
{
	srand((unsigned)(time(0)));
	
	int generation = 0;
	vector<Individual> population;
	bool found = false;
	
	// Baslangic populasyonunu rastgele olusturalim
	for(int i = 0 ; i < POPULATION_SIZE; ++i)
	{
		string genome = create_genome();
		population.push_back(Individual(genome));
	}
	
	// Hedef string bulunana kadar akiyoruz
	while(!found)
	{
		// Fitness degerine gore siralama
		sort(population.begin(),population.end());
		
		// Fitness degeri 0 ise bulundu demektir 
		if(population[0].fitness <= 0)
		{
			found = true;
			break;
		}
		
		vector<Individual> new_generation;
		
		// Elitizm yonemi -> en uygun populasyonun %10unu yeni nesile aktar
		int s = (10*POPULATION_SIZE) / 100;
		for(int i = 0 ; i < s; ++i)
		{
			new_generation.push_back(population[i]);
		}
		
		// En uygunlarin yarisi yeni yavrular olusturacak
		s = (90*POPULATION_SIZE) / 100;
		for(int i = 0; i < s; ++i)
		{
			int r1 = random_num(0,50);
			int r2 = random_num(0,50);
			Individual parent1 = population[r1];
			Individual parent2 = population[r2];
			Individual offspring = parent1.mate(parent2);
			new_generation.push_back(offspring);
		}
		
		// Populasyonu yeni nesil ile degistirelim hedefe kosalim
		population = new_generation;
        cout << "Generation: " << generation << "\t";
        cout << "String: " << population[0].chromosome << "\t";
        cout << "Fitness: " << population[0].fitness << "\n";
		generation++;
	}
	
        cout << "Generation: " << generation << "\t";
        cout << "String: " << population[0].chromosome << "\t";
        cout << "Fitness: " << population[0].fitness << "\n";

	return SUCCESS;
}




















#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// Array of preferences[i][j] is number of voters who prefer candidate i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j // if true existence of an edge from i to j // false no
// edge
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_for_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if the vote name is valid
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    // if not valid return false
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int ci = ranks[i];
            int cj = ranks[j + 1];

            if (ci != cj && cj < candidate_count)
            {
                preferences[ci][cj]++;
            }
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Go throught each row
    for (int i = 0; i < candidate_count; i++)
    {
        // Go throught each column
        for (int j = 0; j < candidate_count; j++)
        {
            // Make sur that has no origin 0's (0,0, 1,1, etc.)
            if (i != j)
            {
                // Make sure that is not a tide pair
                if (preferences[i][j] != preferences[j][i])
                {
                    // Make sure that just one head-to-head is add to the pairs. ex: (0,1 x 1,0 ==
                    // 1,0 x 0,1)
                    if (preferences[i][j] > preferences[j][i])
                    {
                        pairs[pair_count].winner = i;
                        pairs[pair_count].loser = j;
                        pair_count++;
                    }
                }
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        int wi = preferences[pairs[i].winner][pairs[i].loser];
        int li = preferences[pairs[i].loser][pairs[i].winner];
        int d1 = wi - li;

        for (int j = i + 1; j < pair_count; j++)
        {
            int wj = preferences[pairs[j].winner][pairs[j].loser];
            int lj = preferences[pairs[j].loser][pairs[j].winner];
            int d2 = wj - lj;
            int biggest = i;

            if (d1 < d2)
            {
                biggest = j;
            }

            pair temp = pairs[i];
            pairs[i] = pairs[biggest];
            pairs[biggest] = temp;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // Check for the index for w, l from each pair in the list
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // Check if this pair creates a cycle and then add to locked[w][l]
        if (check_for_cycle(winner, loser) == 0)
        {
            locked[winner][loser] = 1;
        }
    }
}

bool check_for_cycle(int winner, int loser)
{
    // Check if l is poiting to w
    if (loser == winner)
    {
        return 1;
    }

    // Check if other candidate poiting to l
    for (int i = 0; i < pair_count; i++)
    {
        // Check if has an arrow
        if (locked[loser][i] == 1)
        {
            // Need to check if i (l) == (w)
            if (check_for_cycle(winner, i) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Print the winner of the election
void print_winner(void)
{
    // GO through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner = 1;

        for (int j = 0; j < candidate_count; j++)
        {
            // Ckeck if the candidate is on the list of not_winner
            if (locked[j][i] == 1)
            {
                winner = 0;
                break;
            }
        }

        if (winner == 1)
        {
            printf("Winner is %s\n", candidates[i]);
            break;
        }
    }
}

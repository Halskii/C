#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


// Contains pointers to words within a trie.
typedef struct dictionary_trie_node {
	int count;
	char *definition;

	struct lex_node *child[26];
} lex_node;


// Holds basic contributing user data in nodes for a linked list.
typedef struct nodes_of_contributors {
	time_t date_ctr;
	char *word_ctr;
	char *scr_name;

	struct usr_node *next;
} usr_node;


// The Heads Of Linked Lists For Hashing Table.
typedef struct list_of_users {
	int num_of_names;

	usr_node *head;
} user_list;


// Handler for Hashing Table -> Linked Lists Sorting Users.
typedef struct user_database {
	int total_users;

	user_list *user_list[26];
} hash_table;


// Inserts a new definiton and word into our Lexicon trie.
Lexicon *insert_def (Lexicon *lex, char *word, char *def) {
	int i, index, len = strlen(str);
	TrieNode *wizard;

	if (root == NULL)
		root = createNode();

	// As I mentioned in class, the wizard starts at the root node and spells
	// out the string being inserted as he/she jumps from node to node. (The
	// wizard is acting as a temp pointer.)
	wizard = root;

	for (i = 0; i < len; i++)
	{
		// This is kind of gross. There are probably cleaner ways of dealing with
		// this than simply printing an error and returning NULL.
		if (!isalpha(str[i]))
		{
			fprintf(stderr, "Error: \"%s\" contains non-alpha characters and will not be inserted.\n", str);
			return NULL;
		}

		index = tolower(str[i]) - 'a';

		// Before the wizard can move forward to the next node, (s)he needs to
		// make sure that node actually exists. If not, create it!
		if (wizard->children[index] == NULL)
			wizard->children[index] = createNode();

		// Now the wizard is able to jump forward.
		wizard = wizard->children[index];
	}

	// When we break out of the for-loop, the wizard should be at the terminal
	// node that represents the string we're trying to insert.
	wizard->count++;
	return root;
	}

}


// Modifys or changes a definition for a specific word in our Lexicon trie.
Lexicon *modify_def (Lexicon *lex, char *word, char *new_def) {

}


// Retrieves and prints a word's definition from our Lexicon trie.
Lexicon *search_word (Lexicon *lex, char *word) {


}


usr_node *create_user (char *word_ctr, char *scr_name, time_t date) {


}


// Adds a user to our hash table.
hash_table *add_user (hash_table *user_database, char *word_ctr, char *scr_name) {

	usr_node *new_user = NULL;

	if(user_database == NULL)
		return NULL;

	scr_name = toupper(scr_name);

	new_user = calloc(1, sizeof(usr_node));
	strcpy(new_user->word_ctr, word_ctr);
	strcpy(new_user->scr_name, scr_name);
	new_user->date_ctr = time(NULL);

	}
}


// Open an input file and build a trie from its contents. Assumes the input file
// contains no punctuation.
 Lexicon *buildTrie(char *filename)
{
	TrieNode *root = NULL;
	char buffer[MAX_WORD_LENGTH + 1];

	FILE *ifp;

	if ((ifp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Failed to open \"%s\" in buildTrie().\n", filename);
		return NULL;
	}

	// Insert strings one-by-one into the trie.
	while (fscanf(ifp, "%s", buffer) != EOF)
		root = insert(root, buffer);

	fclose(ifp);
	return root;
}


int main(void)
{
	TrieNode *root = buildTrie("corpus.txt");
	printTrie(root);

	// Stretch goal: Write a function that recursively destroys your trie.

	return 0;
}

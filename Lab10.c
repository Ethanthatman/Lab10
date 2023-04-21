#include <stdio.h>
#include <stdlib.h>

struct TrieNode
{
    int count;
    struct TrieNode *children[26];
};

struct TrieNode *returnNode(void)
{
    struct TrieNode *pNode = malloc(sizeof(struct TrieNode));
    pNode->count=0;
    for(int x = 0; x < 26;x++)
    {
        pNode->children[x] = NULL;    
    }
    return pNode;
}

void insert(struct TrieNode *ppTrie, char *word)
{
    struct TrieNode *tmp = ppTrie;
    int x = 0;
    while(word[x] != '\0')
    {
        int index =  word[x] - 'a';
        if(tmp->children[index] == NULL)
        {
            tmp->children[index] = returnNode();

        }
        tmp=tmp->children[index];
        x++;
    }
    tmp->count++;
}
int numberOfOccurances(struct TrieNode *pTrie, char *word)
{
    int x = 0;
    struct TrieNode *tmp = pTrie;
    while(word[x] != '\0')
    {
        int index = word[x] - 'a';
        tmp=tmp->children[index];
        x++;
    }
    return tmp->count;
}
struct TrieNode *deallocateTrie(struct TrieNode *pTrie)
{
    if(pTrie = NULL)
    {
        return NULL;
    }
    
    for(int x = 0; x < 26; x++)
    {
        if(pTrie != NULL)
        {
            deallocateTrie(pTrie->children[x]);
        }
        
    }
    free(pTrie);
    return NULL;
}

int main(void)
{
    //read the number of the words in the dictionary
    // parse line  by line, and insert each word to the trie data structure
    struct TrieNode *pTrie = returnNode();
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for(int x = 0; x < 5;x++)
    {
        insert(pTrie, pWords[x]);
    }
    for (int i=0;i<5;i++)
    {
        printf("\t%s : %d\n",pWords[i], numberOfOccurances(pTrie, pWords[i]));
    }
    pTrie = deallocateTrie(pTrie);
    
    if (pTrie != NULL)
    {
        printf("There is an error in this program\n");
    }
    return 0;
}



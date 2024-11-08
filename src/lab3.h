/**
 * Fills an array of strings with book titles input by the user.
 * 
 * @param titles An array of string pointers to be filled with book titles.
 * @param size The number of book titles to be read and stored.
 */
void fillTitles(char **titles, int size);

/**
 * Prints a list of strings to standard output, each string on a new line, 
 * prefixed with its order in the list starting from 1.
 * 
 * @param titles An array of string pointers representing book titles to print.
 * @param size The number of book titles in the array.
 */
void printList(char **titles, int size);

/**
 * Fills an array of strings with user-selected favorite book titles from an
 * existing array of all book titles.
 * 
 * @param favorites An array of string pointers to be filled with selected favorite book titles.
 * @param numFavs The number of favorite book titles selected.
 * @param titles The original array of all book titles from which favorites are selected.
 */
void fillFavorites(char **favorites, int numFavs, char **titles);

/**
 * Writes the list of all book titles and separately the list of favorite book titles 
 * to a user-specified file.
 * 
 * @param titles An array of string pointers representing all book titles.
 * @param size The number of all book titles.
 * @param favorites An array of string pointers representing selected favorite book titles.
 * @param numFavs The number of selected favorite book titles.
 */
void printToFile(char **titles, int size, char **favorites, int numFavs);

/**
 * Frees the memory allocated for storing book titles.
 * 
 * @param titles An array of string pointers representing book titles to be freed.
 * @param size The number of book titles in the array.
 */
void freeBookTitles(char **titles, int size);

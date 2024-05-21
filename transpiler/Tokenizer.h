//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_TOKENIZER_H
#define DEMOPROJECT_TOKENIZER_H

#include <string>
#include "Token.h"

/**
 * Tokenize the input string into a vector of tokens.
 *
 * @param input The input string to be tokenized.
 * @return A vector of tokens representing the input string.
 */
std::vector<Token> tokenize(const std::string& input);

/**
 * Repeat a string a specified number of times.
 *
 * @param str The string to be repeated.
 * @param count The number of times to repeat the string.
 * @return The repeated string.
 */
std::string repeat(const std::string &str, unsigned long count);

#endif //DEMOPROJECT_TOKENIZER_H

#include "WordCounter.h"
#include "WordCounterBuilder.h"
#include "WordCounterSettingsBuilder.h"
#include "WordCounterInputBuilder.h"
#include "generateStringTextInput.hpp"
#include <gtest/gtest.h>
#include <numeric>
#include <string>
#define RESOURCES_DIR "../../Resources"

#define TEST_ALL

#ifdef TEST_ALL
#define TEST_WORDCOUNTER
#endif

#ifdef TEST_WORDCOUNTER
#define TEST_INPUT
#define TEST_DELIMITER
#define TEST_FILTER
#define TEST_KEYWORD
#endif

#ifdef TEST_INPUT
#define TEST_FILEINPUT
#define TEST_TEXTINPUT
#endif

#ifdef TEST_FILEINPUT
#define TEST_FILEINPUT_10000_NEWLINE
#define TEST_FILEINPUT_100000_NEWLINE
#define TEST_FILEINPUT_1e06_NEWLINE
#define TEST_FILEINPUT_1e07_NEWLINE
#define TEST_FILEINPUT_1e08_NEWLINE
#define TEST_FILEINPUT_10000_COMMA
#define TEST_FILEINPUT_100000_COMMA
#define TEST_FILEINPUT_1e06_COMMA
#define TEST_FILEINPUT_1e07_COMMA
#define TEST_FILEINPUT_1e08_COMMA
#endif

#ifdef TEST_TEXTINPUT
#define TEST_TEXTINPUT_NEWLINE
#define TEST_TEXTINPUT_COMMA
#endif

#ifdef TEST_DELIMITER
#define TEST_DELIMITER_NEWLINE
#define TEST_DELIMITER_SPACE
#define TEST_DELIMITER_COMMA
#define TEST_DELIMITER_SEMICOLON
#endif

#ifdef TEST_FILTER
#define TEST_FILTER_ALL
#define TEST_FILTER_ALPHA
#define TEST_FILTER_NUM
#define TEST_FILTER_LOWERCASE
#define TEST_FILTER_UPPERCASE
#define TEST_FILTER_SPACE
#define TEST_FILTER_ALPHANUM
#define TEST_FILTER_ALPHANUM_SPACE
#endif

#ifdef TEST_KEYWORD
#define TEST_KEYWORD_SMILEY
#define TEST_KEYWORD_WORD
#endif

#ifdef TEST_KEYWORD_SMILEY
#include "WordCounter_Test/Keywords/TEST_KEYWORD_SMILEY.hpp"
#endif
#ifdef TEST_KEYWORD_WORD
#include "WordCounter_Test/Keywords/TEST_KEYWORD_WORD.hpp"
#endif


#ifdef TEST_FILTER_ALL
#include "WordCounter_Test/Filter/TEST_FILTER_ALL.hpp"
#endif
#ifdef TEST_FILTER_ALPHA
#include "WordCounter_Test/Filter/TEST_FILTER_ALPHA.hpp"
#endif
#ifdef TEST_FILTER_NUM
#include "WordCounter_Test/Filter/TEST_FILTER_NUM.hpp"
#endif
#ifdef TEST_FILTER_LOWERCASE
#include "WordCounter_Test/Filter/TEST_FILTER_LOWERCASE.hpp"
#endif
#ifdef TEST_FILTER_UPPERCASE
#include "WordCounter_Test/Filter/TEST_FILTER_UPPERCASE.hpp"
#endif
#ifdef TEST_FILTER_SPACE
#include "WordCounter_Test/Filter/TEST_FILTER_SPACE.hpp"
#endif
#ifdef TEST_FILTER_ALPHANUM
#include "WordCounter_Test/Filter/TEST_FILTER_ALPHANUM.hpp"
#endif
#ifdef TEST_FILTER_ALPHANUM_SPACE
#include "WordCounter_Test/Filter/TEST_FILTER_ALPHANUM_SPACE.hpp"
#endif



#ifdef TEST_DELIMITER_NEWLINE
#include "WordCounter_Test/Delimiter/TEST_DELIMITER_NEWLINE.hpp"
#endif
#ifdef TEST_DELIMITER_SPACE
#include "WordCounter_Test/Delimiter/TEST_DELIMITER_SPACE.hpp"
#endif
#ifdef TEST_DELIMITER_COMMA
#include "WordCounter_Test/Delimiter/TEST_DELIMITER_COMMA.hpp"
#endif
#ifdef TEST_DELIMITER_SEMICOLON
#include "WordCounter_Test/Delimiter/TEST_DELIMITER_SEMICOLON.hpp"
#endif


#ifdef TEST_TEXTINPUT_NEWLINE
#include "WordCounter_Test/Input/TextInput/TEST_TEXTINPUT_NEWLINE.hpp"
#endif
#ifdef TEST_TEXTINPUT_COMMA
#include "WordCounter_Test/Input/TextInput/TEST_TEXTINPUT_COMMA.hpp"
#endif

#ifdef TEST_FILEINPUT_10000_NEWLINE
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_10000_NEWLINE.hpp"
#endif

#ifdef TEST_FILEINPUT_10000_COMMA
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_10000_COMMA.hpp"
#endif

#ifdef TEST_FILEINPUT_100000_NEWLINE
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_100000_NEWLINE.hpp"
#endif

#ifdef TEST_FILEINPUT_100000_COMMA
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_100000_COMMA.hpp"
#endif

#ifdef TEST_FILEINPUT_1e06_NEWLINE
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e06_NEWLINE.hpp"
#endif

#ifdef TEST_FILEINPUT_1e06_COMMA
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e06_COMMA.hpp"
#endif

#ifdef TEST_FILEINPUT_1e07_NEWLINE
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e07_NEWLINE.hpp"
#endif

#ifdef TEST_FILEINPUT_1e07_COMMA
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e07_COMMA.hpp"
#endif

#ifdef TEST_FILEINPUT_1e08_NEWLINE
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e08_NEWLINE.hpp"
#endif

#ifdef TEST_FILEINPUT_1e08_COMMA
#include "WordCounter_Test/Input/FileInput/TEST_FILEINPUT_1e08_COMMA.hpp"
#endif


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}
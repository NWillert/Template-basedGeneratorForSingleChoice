#ifndef QUESTION_H
#define QUESTION_H



//Class for instantiating a question, with all necessary values. so that all questions can be stored at creation, and be later used to write the corresponding xmls
class Question
{
public:
    Question(int Id, std::string q_name, std::string q_author, std::string q_description, std::string q_additionalText, std::string q_code, std::string q_taxonomy, std::string q_task,
        std::string q_correctAnswer, std::string q_wrongAnswerOne, std::string q_wrongAnswerTwo, std::string q_wrongAnswerThree, Picture q_picture);

    int GetQuestionId();
    std::string GetName();
    std::string GetAuthor();
    std::string GetDescription();
    std::string GetCode();
    std::string GetAdditionalText();
    std::string GetTaxonomy();
    std::string GetTask();
    std::string GetCorrectAnswer();
    std::string GetWrongAnswerOne();
    std::string GetWrongAnswerTwo();
    std::string GetWrongAnswerThree();
    bool IsCodeEmpty();
    bool IsAdditionalTextEmpty();
    bool IsTaxonomyEmpty();
    Picture GetPicture();
private:
    int questionId;
    std::string name{}, author{}, description{}, code{}, additionalText{}, taxonomy{}, task{}, correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
    Picture picture;
};

#endif 
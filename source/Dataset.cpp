#include "Dataset.h"
#include "Page.h"

void Dataset::preprocessing() {

  interactions_table_ = torch::zeros({get_documents_count(),
                                      get_flashcards_count()});


  for (int i = 0; i < flashcards_id_.size(); ++i)
  {
    for (int j = 0; j < documents_id_.size(); ++j)
    {
      interactions_table_.index_put_({j, i}
          , get_mark(documents_id_[j], flashcards_id_[i]));
    }
  }

  std::cout << interactions_table_ << std::endl;

}

int Dataset::get_mark(int p_doc_id, int p_card_id) {
  for (const Data_t &i: interactions_data_) {
    if (i.doc_id == p_doc_id && i.card_id == p_card_id) {
      return i.mark;
    }
  }
  return 0;
}


const torch::Tensor &Dataset::get_interaction_table() const {
  return interactions_table_;
}

const int Dataset::get_documents_count() const {
  return documents_id_.size();
}

const int Dataset::get_flashcards_count() const {
  return flashcards_id_.size();
}

const std::vector<Dataset::Data_t> &Dataset::get_interactions_data() const {
  return interactions_data_;
}

const std::vector<int> Dataset::get_documents() const {
  return documents_id_;
}

const std::vector<int> Dataset::get_flashcards() const {
  return flashcards_id_;
}

Dataset::Dataset(const Dataset &other)
    : documents_id_(other.documents_id_)
    , flashcards_id_(other.flashcards_id_)
    , interactions_data_(other.interactions_data_)
    , interactions_table_(other.interactions_table_)
{
}

const Dataset &Dataset::operator=(const Dataset &other) {
  documents_id_ = other.documents_id_;
  flashcards_id_ = other.flashcards_id_;
  interactions_data_ = other.interactions_data_;
  interactions_table_ = other.interactions_table_;
  return (*this);
}

Dataset::Dataset(const std::vector<int> &pages)
    : documents_id_(pages)
{

  for (auto p: pages) {
    Page page(std::to_string(p), true);
    Data_t temp;
    ////
    std::vector<std::vector<std::string>> vec = page.get_all_rec_question_marks_and_id();

    ////
    for (const auto &i: page.get_all_rec_question_marks_and_id()) {
      temp.doc_id = p;
      temp.card_id = std::stoi(i[0]);
      temp.mark = std::stoi(i[1]);

      interactions_data_.push_back(temp);

      flashcards_id_.push_back(std::stoi(i[0]));
    }
  }

  ////test
  for (const auto &i: interactions_data_) {
    std::cout << i.doc_id << i.card_id << i.mark << std::endl;
  }
  ////
  preprocessing();
}



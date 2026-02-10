template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    this->length++;
    if(this->head == nullptr)
    {
        this->head = new Node(elem, nullptr);
        return;
    }

    typename LinkedList<T>::Node* current = this->head;
    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new Node(elem, nullptr);
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    while(this->head != nullptr)
    {
        typename LinkedList<T>::Node* nextNode = this->head->next;
        delete this->head;
        this->head = nextNode;
    }
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO

    //going to assume user knows if the list is empty

    typename LinkedList<T>::Node* current = this->head; //element zero
    for(int i = 0; i < position; i++)
    {
        current = current->next;
    }
    return current->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    typename LinkedList<T>::Node* current = this->head; //element zero
    for(int i = 0; i < position; i++)
    {
        current = current->next;
    }

    current->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
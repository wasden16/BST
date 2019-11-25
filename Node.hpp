#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
  public:
    Node(T data)
      : m_data(data), m_pLeft(NULL), m_pRight(NULL)
	{
		//Emtpy
    }

    T getData(void)
    {
      return m_data;
    }

    Node<T>* getLeft(void)
    {
      return m_pLeft;
    }

	Node<T>* getRight(void)
	{
		return m_pRight;
	}

    void setLeft(Node<T>* next)
    {
      m_pLeft = next;
    }

	void setRight(Node<T>* next)
	{
		m_pRight = next;
	}

  private:
    Node<T>* m_pRight;
	Node<T>* m_pLeft;
    T m_data;
};

#endif // NODE_HPP
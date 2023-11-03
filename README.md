
# Library Management Syetem using BST

This project is a Library Management System that utilizes the Binary Search Tree (BST) data structure to efficiently manage books and their quantities. The system is designed to be user-friendly, offering two main interfaces for both administrators and users.

### Administrator Features

Administrators are required to enter valid credentials to access the e-library database. Once authenticated, they have the following controls:

- **Add Book:** Administrators can add new books to the library, specifying the book's name and quantity. The system keeps track of the inventory.
- **Delete Book:** Books can be removed from the library. If no books remain, the library is emptied.
- **Update Book:** Administrators can modify the quantity of existing books in the library.
- **Display Books:** This feature allows administrators to view the entire library inventory, presented in sorted order.

### User Features

Users must provide a valid university ID to access the e-library. They have access to the following options:

- **Issue Book:** Users can borrow books from the library. The system allows them to issue only one book at a time.

- **Return Book:** After reading, users can return the book they borrowed. It's important to note that users must return an issued book within 1.5 months from the date of issue.

### Key BST Concepts Applied

Key concepts applied include the ability to insert new books into the library, maintaining order based on the book's name, ensuring that the library remains sorted. Additionally, in-order traversal of the BST is employed to display the library's books in a sorted manner, making it easier for administrators and users to navigate. The system allows for searching, enabling users to find books and administrators to check for the existence of a book before adding it. Deletion of books is also handled within the BST, ensuring the library's inventory is updated accurately. Furthermore, quantity tracking is a crucial aspect, ensuring the system keeps track of the number of books available at any given time. 
public class LinkedList<T> {

	/* Internal Node Representation */
	private class Node {
		private T data;
		private Node next;
		Node (T data) {
			this.data = data;
			this.next = null;
		}
	}

	private Node head;
	private int size;

	/*
		Creates an empty Linked List
	*/
	public LinkedList() {
		this.head = null;
		this.size = 0;
	}

	/*
		Adds new node containing specified data to end of Linked List
	*/
	public void add(T data) {
		if (this.head == null) {
			this.head = new Node(data);
		} else {
			_add(this.head, data);
		}
		this.size++;
	}

	private void _add(Node node, T data) {
		while (node.next != null) {
			node = node.next;
		}
		node.next = new Node(data);
	}

	/*
		Removes the first node in the Linked List containing T data
		if no node exists then nothing is deleted and false is returned
	*/
	public boolean remove(T data) {
		if (this.head.data.equals(data)) {
			this.head = this.head.next;
			this.size--;
			return true;
		} else {
			return _remove(this.head, data);
		}
	}

	private boolean _remove(Node node, T data) {
		while (node.next != null) {
			if (node.next.data.equals(data)) {
				node.next = node.next.next;
				this.size--;
				return true;
			}
			node = node.next;
		}
		return false;
	}

	/*
		Returns the number of nodes in the Linked List
	*/
	public int getNumNodes() {
		return this.size;
	}

	/*
		Returns a string representation of the Linked List
	*/
	public String toString() {
		StringBuffer buffer = new StringBuffer();
		Node node = this.head;
		while (node != null) {
			buffer.append(node.data);
			if (node.next != null) {
				buffer.append(" -> ");
			}
			node = node.next;
		}
		return buffer.toString();
	}

	/*
		Debugging/Testing
	*/
	/*
	public static void main(String args[]) {
		LinkedList<Integer> list = new LinkedList<>();
		list.add(3);
		list.add(4);
		list.add(5);
		System.out.println(list);
		System.out.println("Size: " + list.getNumNodes());
		list.remove(5);
		System.out.println(list);
		System.out.println("Size: " + list.getNumNodes());
	}
	*/
}
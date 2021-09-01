class Node:
	def __init__(self, word=None):
		self.word = word
		self.next = None

# your code goes here
def cyclic_shift(head, k) -> Node:
    

def print_list(head):
	cur = head;
	while cur != None:
		print(cur.word, end=" ")
		cur = cur.next
	print(end="\n")

def main():
	n, k = map(int, input().split())
	a = input().split()
	head = None
	cur = None
	for word in a:
		if head == None:
			head = Node(word)
			cur = head
		else:
			cur.next = Node(word)
			cur = cur.next

	head = cyclic_shift(head, k)
	print_list(head)

if __name__ == '__main__':
	main()
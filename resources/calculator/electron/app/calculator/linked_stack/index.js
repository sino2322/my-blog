'use strict';

function Node(element) {
    this.element = element;
    this.next = null;
}

function LinkedStack() {
    this.length = 0;
    this.root = new Node('root');
    this.top = this.root;
    this.push = push;
    this.pop = pop;
    this.len = len;
    this.init = init;
    this.getTop = getTop;
}

function push(element) {
    let newNode = new Node(element);
    newNode.next = this.top;
    this.top = newNode;
    this.length++;
}

function pop() {
    if (this.length > 0) {
        let deleteNode = this.top;
        this.top = deleteNode.next;
        this.length--;
        return deleteNode.element;
    }
    return null;
}

function getTop() {
    return this.top.element;
}

function len() {
    return this.length;
}

function init() {
    while (this.length > 0) this.pop();
    this.length = 0;
}

module.exports.new = () => new LinkedStack();
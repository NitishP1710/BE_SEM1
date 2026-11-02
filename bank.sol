
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.38;

contract Bank {

    mapping(address => uint256) public balances;

    event Deposited(address indexed user, uint256 amount);
    event Withdrawn(address indexed user, uint256 amount);

    // Deposit ETH into bank
    function deposit() public payable {
        require(msg.value > 0, "Amount must be greater than zero");

        balances[msg.sender] += msg.value;

        emit Deposited(msg.sender, msg.value);
    }

    // Withdraw ETH from bank
    function withdraw(uint256 amount) public {
        require(amount > 0, "Amount must be greater than zero");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;

        (bool success, ) = payable(msg.sender).call{value: amount}("");

        require(success, "Transfer failed");

        emit Withdrawn(msg.sender, amount);
    }

    // Display account balance
    function getBalance(address user) public view returns (uint256) {
        return balances[user];
    }
}

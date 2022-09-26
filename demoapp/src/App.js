import React from 'react';
import logo from './logo.svg';
import './App.css';

// function based components

// function App() {
// 	return (
//		this is not HTML, this is JSX
// 		<div className='App'>
// 			<header className='App-header'>
// 				<img src={logo} className='App-logo' />
// 				<p>Learn React</p>
// 			</header>
// 		</div>
// 	);
// }

// export default App;

// class based components

class App extends React.Component {

	constructor(props) {
		super(props);
		this.state = {
			newItem: "",
			list: []
		}
	}

	addItem(todoValue) {
		if (todoValue !== "") {
			const newItem = {
				id: Date.now(),
				value: todoValue,
				isDone: false
			};
			// this new item should be pushed in the list
			const list = [...this.state.list];	// ... means all the items in the state.list will be in this list
			list.push(newItem);
			// this only updates the local list
			// we need to update the actual list
			this.setState({
				// list: list,
				list,
				// since same name so no need to write like line 46
				newItem: ""
			});
		}
	}

	deleteItem(id) {
		// get the copy of the list
		const list = [...this.state.list];
		const updateList = list.filter(item => item.id !== id);
		// this will create a new list which have all the items except that which matched the id
		this.setState({list: updateList});
	}

	updateInput(input) {
		this.setState({newItem: input});
	}

	render() {
		return(
			// this is not HTML, this is JSX
			<div>
				<img src={logo} width="100" height="100" className="logo" />
				<h1 className='app-title'>ToDo App</h1>
				<div className='container'>
					Add an Item...
					<br/>
					<input
						type="text"
						className='input-text'
						placeholder='Write a Todo'
						required
						value={this.state.newItem}
						onChange={e => this.updateInput(e.target.value)}
						// onChange, it will get the value and pass it into the method
					/>
					<button
						className='add-btn'
						onClick={() => this.addItem(this.state.newItem)}
						disabled={!this.state.newItem.length}
						>
						Add Todo
					</button>
					<div className='list'>
						<ul>
							{this.state.list.map(item => {
								return(
									<li key={item.id}>
										<input
											type="checkbox"
											name="idDone"
											checked={item.isDone}
											onChange={() => {}}
										/>
										{item.value}
										<button
											className='btn'
											onClick={() => this.deleteItem(item.id)}
											>
											Delete
										</button>
										<button
											className='btn'
											>
											Done
										</button>
									</li>
								)
							})}
							{/* <li>
								<input type="checkbox" name='' id=''/>
								Record Lectures
								<button className='btn'>Delete</button>
							</li> */}
						</ul>
					</div>
				</div>
			</div>
		);
	}
}

export default App;
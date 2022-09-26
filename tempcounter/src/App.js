import React from "react";
import "./App.css"

class App extends React.Component {
	render() {
		return(
			<div className="display">
				<div className="frame">
					<center>
						<div className="temp">0</div>
					</center>
				</div>
				<div className="btns">
					<div className="left">
						<button>
							Increase
						</button>
					</div>
					<div className="right">
						<button>
							Decrease
						</button>
					</div>
				</div>
			</div>
		);
	}
}

export default App;
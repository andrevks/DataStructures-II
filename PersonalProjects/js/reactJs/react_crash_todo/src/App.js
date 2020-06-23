import React, { Component } from 'react';
import Todos from './components/Todos';
import './App.css';

class App extends Component {
  state = {
    todos: [
      {
        i:1,
        title: 'Read the Brain Rules\'s book',
        completed:false
      },
      {
        id:2,
        title: 'Write pages for your new book',
        completed:false
      },
      {
        id:3,
        title: 'Make app with React Js',
        completed:false
      },
    ]

  }

  render(){
    return (
      <div className="App">
        <Todos todos={this.state.todos} />
      </div>
    );
  }
}

export default App;

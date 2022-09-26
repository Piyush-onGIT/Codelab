import React from "react";
import {FaTimes, FaPen, FaRegCircle} from 'react-icons/fa'

const Icon = ({ name }) => {
    switch (name) {
        case 'circle':
            return <FaRegCircle className="icon" color="black"/>
        case 'cross':
            return <FaTimes className="icon" color="black"/>
        default:
            return <FaPen className="icon" color="black"/>;
    }
}

export default Icon;
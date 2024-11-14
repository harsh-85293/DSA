const express = require('express');
const mongoose = require('mongoose');
const cors = require('cors');

const app = express();
const port = 3000;

const FoodModel=require('./Food.js');

app.use(express.json());
app.use(cors());

mongoose.connect('mongodb+srv://harshramchandani122003:harsh123@cluster0.l5tud.mongodb.net/');
app.post('/insert',async(req,res)=>{
    const foodName = req.body.foodName;
    const days = req.body.days;
    const food = new FoodModel({
        foodName:foodName,daysSinceIate:days
    })
    try{
        await food.save();
         res.send("inserted data");
    }
    catch(err){
        console.log(err);
    }
})

app.get('/read',async(req,res)=>{
    try{
        const result = await FoodModel.fine({});
        res.send(result);
    }
    catch(err){
        console.log(err);
    }
})

app.put('/update',async(req,res)=>{
    const newFoodName = req.body.newFoodName;
    const id = req.body.id;
    try{
        const updatedFood = await FoodModel.findById(id);
        updatedFood.foodName = newFoodName;
        updatedFood.save();
    }
    catch(err){
console.log(err);
    }
})

app.delete('/delete/:id',async(req,res)=>{
    try{
        const id=req.params.id;
        await FoodModel.findByIdAndDelete(id);
        res.send("Deleted");
    }
    catch(err){
        console.log(err);
    }
})


app.listen(port,()=>{
    console.log(`Server running at http://localhost:${port}`);
})
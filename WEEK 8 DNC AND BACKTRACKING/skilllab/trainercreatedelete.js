const mongoose = require("mongoose");

const mongo_url =
    "mongodb+srv://harshramchandani122003:harsh123cluster0.l5tud.mongodb.net/";

const connectToMongo = async() => {
    mongoose.Promise = global.Promise;

    try {
        await mongoose.connect(mongo_url);
        console.log("Connected to MongoDB");
    } catch (err) {
        console.error("Error connecting to MongoDB", err);
        process.exit(1);
    }
};

const collection_name = "trainer";
const collection_fields = {
    name: String,
    location: String,
    technology: String,
    phone_number: String,
};
const collection_config = {
    timestamps: false,
};

const schema = mongoose.Schema(collection_fields, collection_config);
const TrainerModel = mongoose.model(collection_name, schema);



const deletebyName = async() => {
    await connectToMongo();
    try {

        const result = await TrainerModel.deleteOne({ name: 'Manav' });
        if (result.deletedCount > 0) {
            console.log('Trainer deleted');
        } else {
            console.log('No trainer found with that name');
        }
    } catch (err) {
        console.log(err)

    } finally {
        await mongoose.disconnect();
        console.log('connection closed')
    }
}
deletebyName();